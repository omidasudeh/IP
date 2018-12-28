/*
*
*
*
This program illustrates counting available devices,
compile it with nvcc and note the extension .cu
and for a more detailed version, see deviceQuery.cpp
of the GPU Computing SDK */
#include <stdio.h>
void printDeviceProp ( cudaDeviceProp p )
/*
* prints some device properties */
{
    printf(" name : %s \n",p.name);
    printf(" number of multiprocessors : %d \n",
    p.multiProcessorCount);
}
int main ( int argc, char* argv[] )
{
    int deviceCount;
    cudaGetDeviceCount(&deviceCount);
    printf("number of devices : %d\n",deviceCount);
    for(int d = 0; d < deviceCount; d++)
    {
        cudaDeviceProp dev;
        cudaGetDeviceProperties(&dev,d);
        printf("graphics card %d :\n",d);
        printDeviceProp(dev);
    }
    return 0;
}