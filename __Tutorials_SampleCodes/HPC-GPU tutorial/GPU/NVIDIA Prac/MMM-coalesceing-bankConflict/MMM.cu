#include<stdio.h>
#include<stdlib.h>
__global__ void MMM(float* A, float*B, float*C, int m, int w)
{
//    extern __shared__ int a[];
    __shared__ float a_tile[32][32];
    __shared__ float b_tile[32][32];// should I use padding to avoid shared memory bank conflicts
    int by = blockIdx.y;          int bx = blockIdx.x;
    int ty = by*w+threadIdx.y;    int tx =bx*w+threadIdx.x;
    int cval = 0;
    for(int k = 0; k<=m/w;k++)
    {
        //each thread load its element of A and B into shared memory tiles
        // load tile a_tile = A[by][k], b_tile = B[k][bx]
        a_tile[threadIdx.y][threadIdx.x] = A[(by*w+threadIdx.y)*m // same for all threads in the warp
                                             +k*w+threadIdx.x];// access to conseq elelments in global memory
        b_tile[threadIdx.y][threadIdx.x] = B[(k*w+threadIdx.y)*m
                                             +bx*w+threadIdx.x];
        __syncthreads();//why?   
        for(int i = 0;i<w;i++)
            cval+= a_tile[threadIdx.y][i]*b_tile[i][threadIdx.x];
        __syncthreads();//why? 
    }
    C[ty*m+tx] = cval;       
}
void print(float* a, int dim)
{
    printf("\n");
    for (int i = 0;i<dim;i++){
        for (int j = 0;j<dim;j++)
            printf("%f   ",a[i*dim+j]);
        printf("\n");
    }

}
int main(int argc, char** argv)
{
    //1. allocate and initiate host data
        float *H_A, *H_B, *H_C;
        int dim = 1024*4;
        int m = dim*dim;
        int memory_size = m*sizeof(float);
        H_A = (float*) malloc(memory_size);
        H_B = (float*) malloc(memory_size);
        H_C = (float*) malloc(memory_size);
        time_t t;
        srand((unsigned) time(&t));
        for(int i = 0;i<m;i++)
        {
            float ta  = rand()%5;
            H_A[i] = ta;
            float tb =  rand()%5;
            H_B[i] = tb;
        }
    //2. allocate and initiate device data
        float *D_A, *D_B, *D_C;
        cudaMalloc((void**)&D_A, memory_size);
        cudaMalloc((void**)&D_B, memory_size);
        cudaMalloc((void**)&D_C, memory_size);
    //3. thread hierarchy
        int by, bx, gy, gx;
        int bdim = 32;
        int gdim = dim/bdim;
        by = bdim; bx = bdim;
        gy = gdim; gx = gdim;
        dim3 dimBlock(by, bx);
        dim3 dimGrid(gy,gx);
    //4. transfer data from host to device
        cudaMemcpy(D_A,H_A,memory_size,cudaMemcpyHostToDevice);
        cudaMemcpy(D_B,H_B,memory_size,cudaMemcpyHostToDevice);
    //5. run the kernel
        MMM<<<dimGrid,dimBlock>>>(D_A,D_B,D_C,dim, bdim);
    //6. transfer result from device to host
        cudaMemcpy(H_C,D_C,memory_size,cudaMemcpyDeviceToHost);        
    //7. show the result
        // print(H_C);
        // print(H_A, dim);
        // print(H_B, dim);
        // print(H_C, dim);
    //8. free the device memory
        cudaFree(D_A);
        cudaFree(D_B);
        cudaFree(D_C);

    return 0;
}