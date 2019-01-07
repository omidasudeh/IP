#include "calc.h"
#include <stdexcept>
using namespace std;
int calculator::fact(int val){
    if(val<0)
        return 0;
    int f0 = 1;
    int f1 = 1;
    int f2 = 2;
    if(val == 0 )
        return f0;
    if(val == 1 )
        return f1;
    if(val == 2)
        return f2;
    for(int i=3 ; i<=val;i++)
    {
        f0 = f1;
        f1 = f2;
        f2 = f1 + f0;
    }
    return f2;
}
float calculator::div(int v1, int v2){
/*
namespace std {
    class logic_error;
        class domain_error;
        class invalid_argument;
        class length_error;
        class out_of_range;
    class runtime_error;
        class range_error;
        class overflow_error;
        class underflow_error;
}
*/
    if(v2 == 0)
        throw std::domain_error("div/0"); 
    
 return v1/v2;
}