// L-30 MCS 572 Mon 31 Oct 2016 : cudaDoubleComplex.cu
// Our complex double precision numbers use the double2 type,
// double2 is a native CUDA type allowing for coalesced 256 byte access.

#ifndef __CUDADOUBLECOMPLEX_CU__
#define __CUDADOUBLECOMPLEX_CU__

#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <vector_types.h>
#include <math_functions.h>

typedef double2 cudaDoubleComplex;

__host__ cudaDoubleComplex randomDoubleComplex()
// Returns a complex number on the unit circle
// with angle uniformly generated in [0,2*pi].
{
   cudaDoubleComplex result;
   int r = rand();
   double u = double(r)/RAND_MAX;
   double angle = 2.0*M_PI*u;
   result.x = cos(angle);
   result.y = sin(angle);
   return result;
}

__device__ double radius ( const cudaDoubleComplex c )
// Returns the radius of the complex number.
{
   double result;
   result = c.x*c.x + c.y*c.y;
   return sqrt(result);
}

__host__ std::ostream& operator<<
 ( std::ostream& os, const cudaDoubleComplex& c)
// Writes real and imaginary parts of c,
// in scientific notation with precision 16.
{
   os << std::scientific << std::setprecision(16)
      << c.x << "  " << c.y;
   return os;
}

__device__ cudaDoubleComplex operator+
 ( const cudaDoubleComplex a, const cudaDoubleComplex b )
// Returns the sum of a and b.
{
   cudaDoubleComplex result;
   result.x = a.x + b.x;
   result.y = a.y + b.y;
   return result;
}

__device__ cudaDoubleComplex operator-
 ( const cudaDoubleComplex a, const cudaDoubleComplex b )
// Returns the difference of a minus b.
{
   cudaDoubleComplex result;
   result.x = a.x - b.x;
   result.y = a.y - b.y;
   return result;
}

__device__ cudaDoubleComplex operator* 
 ( const cudaDoubleComplex a, const cudaDoubleComplex b )
// Returns the product of a and b.
{
   cudaDoubleComplex result;
   result.x = a.x*b.x - a.y*b.y;
   result.y = a.x*b.y + a.y*b.x;
   return result;
}

__device__ cudaDoubleComplex operator/
 ( const cudaDoubleComplex a, const cudaDoubleComplex b )
// Returns the division of a by b.
{
   cudaDoubleComplex result;
   double d = b.x*b.x + b.y*b.y;
   result.x = (a.x*b.x + a.y*b.y)/d;
   result.y = (a.y*b.x - a.x*b.y)/d;
   return result;
}

#endif
