#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "read_bmp.h"
#include "read_bmp_clib.h"
__global__ void kernel(uint8_t* in_img,uint8_t* out_img,int ht,int wd)
{
    int inX = blockDim.x*blockIdx.x+threadIdx.x;
    int inY = blockDim.y*blockIdx.y+threadIdx.y;
    int outX = wd-inY-1;
    int outY = inX;
    out_img[outX*wd+outY] = in_img [inX*wd+inY];
}
int main(int argc, char** argv)
{
    //1. read the file
	char* input_img_file = argv[1];
    char* cuda_img = argv[2];
    
    //2. allocate host memory
    
	//============== reading the binary bmp file into buffer ==============
	FILE *input_file;
    input_file = fopen(input_img_file,"rb");
    bmp_image img;
	uint8_t *h_bmp_data;
    h_bmp_data = (uint8_t *)img.read_bmp_file(input_file);
    //allocate host memory for result
    uint8_t *h_bmp_result;
    h_bmp_result = (uint8_t*)malloc(img.num_pixel);
    //get image attributes
    int wd = img.image_width;	int ht = img.image_height;
    //3. thread hierarchy: grid is 32*32 blocks. Each block is 32*32 threads. Each thread handles one pixel
        int gridDimX = wd/32;
        int gridDimY = ht/32;
        int blockDimX = 32;
        int blockDimY = 32;

    //4. allocate the Device memory 
    uint8_t *d_bmp_data;
    uint8_t *d_bmp_result;
    cudaMalloc((void**)&d_bmp_data, img.num_pixel);
    cudaMalloc((void**)&d_bmp_result, img.num_pixel);

    //5. pass the data to GPU
    cudaMemcpy(d_bmp_data,h_bmp_data,img.num_pixel,cudaMemcpyHostToDevice);

    //6. run the kernel
    dim3 dimBlock(blockDimX, blockDimY);
    dim3 dimGrid(gridDimX,gridDimY);
    kernel<<<dimBlock, dimGrid>>>(d_bmp_data,d_bmp_result,ht,wd);

    //7. get the result back to the host
    cudaMemcpy(h_bmp_result,d_bmp_result,img.num_pixel,cudaMemcpyDeviceToHost);

	//8. free GPU memory
	cudaFree( h_bmp_data );
	cudaFree( d_bmp_result);

	//9. write back the new bmp image into output file
	FILE *output_file1;
	output_file1 = fopen(cuda_img,"wb");
    img.write_bmp_file(output_file1, h_bmp_result);

    return 0;
}