/* L-33 MCS 572 Mon 7 Nov 2016 : organization.cu 
 * This simple program illustrates a kernel launching a three dimensional
 * grid of three dimensional blocks. */

#include <stdio.h>
#include <stdlib.h>

__global__ void matrixFill ( int *x )
/*
 * Fills the matrix using blockIdx and threadIdx. */
{
   int bx = blockIdx.x;
   int by = blockIdx.y;
   int tx = threadIdx.x;
   int ty = threadIdx.y;
   int row = by*blockDim.y + ty;
   int col = bx*blockDim.x + tx;
   int dim = gridDim.x*blockDim.x;
   int i = row*dim + col;
   x[i] = i; 
}

int main ( int argc, char* argv[] )
{
   const int xb = 2; /* gridDim.x */
   const int yb = 2; /* gridDim.y */
   const int zb = 1; /* gridDim.z */
   const int xt = 2; /* blockDim.x */
   const int yt = 2; /* blockDim.y */
   const int zt = 1; /* blockDim.z */
   const int n = xb*yb*zb*xt*yt*zt;
   printf("allocating array of length %d...\n",n);
   /* allocate, initialize, and copy to device */
   int *xhost = (int*)calloc(n,sizeof(int));
   for(int i=0; i<n; i++) xhost[i] = -1.0;
   int *xdevice;
   size_t sx = n*sizeof(int);
   cudaMalloc((void**)&xdevice,sx);
   cudaMemcpy(xdevice,xhost,sx,cudaMemcpyHostToDevice);
   /* set the execution configuration for the kernel */
   dim3 dimGrid(xb,yb,zb);
   dim3 dimBlock(xt,yt,zt);
   matrixFill<<<dimGrid,dimBlock>>>(xdevice);
   /* copy data from device to host */
   cudaMemcpy(xhost,xdevice,sx,cudaMemcpyDeviceToHost);
   cudaFree(xdevice);
   int *p = xhost;
   for(int i1=0; i1 < xb; i1++)
      for(int i2=0; i2 < yb; i2++)
         for(int i3=0; i3 < zb; i3++)
            for(int i4=0; i4 < xt; i4++)
               for(int i5=0; i5 < yt; i5++)
                  for(int i6=0; i6 < zt; i6++)
                     printf("x[%d][%d][%d][%d][%d][%d] = %d\n",
                             i1,i2,i3,i4,i5,i6,*(p++));
   return 0;
}
