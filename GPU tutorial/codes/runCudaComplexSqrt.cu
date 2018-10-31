// L-30 MCS 572 Fri 31 Oct 2016 : runCudaComplexSqrt.cu
// Using a GPU to compute the square root of n random complex numbers.

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "cudaDoubleComplex.cu"

using namespace std;

__global__ void squareRoot
 ( int n, cudaDoubleComplex *x, cudaDoubleComplex *y )
// Applies Newton's method to compute the square root 
// of the n numbers in x and places the results in y.
{
   int i = blockIdx.x*blockDim.x + threadIdx.x;
   cudaDoubleComplex inc;
   cudaDoubleComplex c = x[i];
   cudaDoubleComplex r = c;
   for(int j=0; j<5; j++)
   {
      inc = r + r;
      inc = (r*r - c)/inc;
      r = r - inc;
   }
   y[i] = r;
}

cudaDoubleComplex Square ( const cudaDoubleComplex z )
// Returns z*z for testing purposes.
{
   cudaDoubleComplex result;
   result.x = z.x*z.x - z.y*z.y;
   result.y = 2*z.x*z.y;
   return result;
}

int main ( int argc, char*argv[] )
{
   if(argc < 5)
   {
      cout << "call with 4 arguments : " << endl;
      cout << "dimension, block size, frequency, and check (0 or 1)" << endl;
   }
   else
   {
      int n = atoi(argv[1]); // dimension
      int w = atoi(argv[2]); // block size
      int f = atoi(argv[3]); // frequency
      int t = atoi(argv[4]); // test or not
      // we generate n random complex numbers on the host
      cudaDoubleComplex *xhost = new cudaDoubleComplex[n];
      for(int i=0; i<n; i++) xhost[i] = randomDoubleComplex();
      // we copy the n random complex numbers to the device
      size_t s = n*sizeof(cudaDoubleComplex);
      cudaDoubleComplex *xdevice;
      cudaMalloc((void**)&xdevice,s);
      cudaMemcpy(xdevice,xhost,s,cudaMemcpyHostToDevice);
      // allocate memory for the result
      cudaDoubleComplex *ydevice;
      cudaMalloc((void**)&ydevice,s);
      // invoke the kernel with n/w blocks per grid
      // and w threads per block
      for(int i=0; i<f; i++)
         squareRoot<<<n/w,w>>>(n,xdevice,ydevice);
      // copy results from device to host
      cudaDoubleComplex *yhost = new cudaDoubleComplex[n];
      cudaMemcpy(yhost,ydevice,s,cudaMemcpyDeviceToHost);
      if(t == 1) // test the result
      {
         int k = rand() % n;
         cout << "testing number " <<  k << endl;
         cout << "        x = " << xhost[k] << endl;
         cout << "  sqrt(x) = " << yhost[k] << endl;
         cudaDoubleComplex z = Square(yhost[k]);
         cout << "sqrt(x)^2 = " << z << endl;
      }
   }
   return 0;
}
