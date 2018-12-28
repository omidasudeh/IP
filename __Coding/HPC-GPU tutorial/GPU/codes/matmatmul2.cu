/* L-31 MCS 572 Wed 2 Nov 2016 : matmatmul2.cu 
 * This file contains a very basic CUDA implementation 
 * of the multiplication of two 0/1 matrices.
 * At the command line the user must give three dimensions: n, m, and p.
 * The program generates a random n-by-m 0/1 matrix A,
 * a random m-by-p 0/1 matrix B, and then computes the product.
 * This version uses the x and y component of threadIdx.  */

#include <stdio.h>
#include <stdlib.h>

__host__ void randomMatrix ( int n, int m, float *x )
/* 
 * Fills up the n-by-m matrix x with random
 * values of zeroes and ones. */
{
   int i,j,r;
   float *p = x;
   for(i=0; i<n; i++)
      for(j=0; j<m; j++)
      {
         r = rand() % 2;
         *(p++) = (float) r;
      }
}

__host__ void writeMatrix ( int n, int m, float *x )
/*
 * Writes the n-by-m matrix x to screen. */
{
   int i,j;
   float *p = x;
   for(i=0; i<n; i++,printf("\n"))
      for(j=0; j<m; j++)
         printf(" %d", (int)*(p++));
}

__global__ void matrixMultiply
 ( int n, int m, int p, float *A, float *B, float *C )
/*
 * Multiplies the n-by-m matrix A 
 * with the m-by-p matrix B into the matrix C.
 * The (i,j)-th thread computes the (i,j)-th element of C. */
{
   int i = threadIdx.x;
   int j = threadIdx.y;
   int ell = i*p + j;
   C[ell] = 0.0;
   float *pB;
   for(int k=0; k<m; k++)
   {
      pB = &B[j+k*p];
      C[ell] += A[i*m+k]*(*pB);
   }
}

int main ( int argc, char*argv[] )
{
   if(argc < 4)
   {
      printf("call with 3 arguments :\n");
      printf("dimensions n, m, and p\n");
   }
   else
   {
      int n = atoi(argv[1]); /* number of rows of A */
      int m = atoi(argv[2]); /* number of columns of A */
                             /* and number of rows of B */
      int p = atoi(argv[3]); /* number of columns of B */
      srand(time(0));
      printf("a random %d-by-%d 0/1 matrix A :\n",n,m);
      float *Ahost = (float*)calloc(n*m,sizeof(float));
      randomMatrix(n,m,Ahost); writeMatrix(n,m,Ahost);
      printf("a random %d-by-%d 0/1 matrix B :\n",m,p);
      float *Bhost = (float*)calloc(m*p,sizeof(float));
      randomMatrix(m,p,Bhost); writeMatrix(m,p,Bhost);
      float *Chost = (float*)calloc(n*p,sizeof(float));
      /* allocate memory on the device for A, B, and C */
      float *Adevice;
      size_t sA = n*m*sizeof(float);
      cudaMalloc((void**)&Adevice,sA);
      float *Bdevice;
      size_t sB = m*p*sizeof(float);
      cudaMalloc((void**)&Bdevice,sB);
      float *Cdevice;
      size_t sC = n*p*sizeof(float);
      cudaMalloc((void**)&Cdevice,sC);
      /* copy matrices A and B from host to the device */
      cudaMemcpy(Adevice,Ahost,sA,cudaMemcpyHostToDevice);
      cudaMemcpy(Bdevice,Bhost,sB,cudaMemcpyHostToDevice);
      /* kernel invocation launching n*p threads */
      dim3 dimGrid(1,1);
      dim3 dimBlock(n,p);
      matrixMultiply<<<dimGrid,dimBlock>>>(n,m,p,Adevice,Bdevice,Cdevice);
      /* copy matrix C from device to the host */
      cudaMemcpy(Chost,Cdevice,sC,cudaMemcpyDeviceToHost);
      /* freeing memory on the device */
      cudaFree(Adevice); cudaFree(Bdevice); cudaFree(Cdevice);
      printf("the resulting %d-by-%d matrix C :\n",n,p);
      writeMatrix(n,p,Chost);
   }
   return 0;
}
