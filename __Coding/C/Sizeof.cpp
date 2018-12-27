#include<iostream>
using namespace std;
int main()
{
    //============= sizeof =====================
    //1.
    int a = 2;
    cout<<sizeof (++a)<<endl<<a<<endl;

    //2.1
    struct c{
        int b[10];//10*4 byte
        char a;   //1 byte
                  //7 byte alignment
        void* t;  //8 byte
    };//56
    struct c1{
        char a;   //0, 1 byte
                  //1-3, 3 byte alignment
        int b;    //4-7, 4 byte
        void* t;  //8-15, 8 byte
    };//16
    struct c2{
        short a;  //0-1, 2 byte
                  //2-3, 2 byte alignment
        int b;    //4-7, 4 byte
        void* t;  //8-15, address 8 byte
    };//16
    struct c3{
        void* t;  //0-7, 8 byte
        int b;    //8-11, 4 byte
                  //12-15, 4 byte alignment
        double* a[10]; //16-95, array of address 8*10 bytes
    };//96
    struct c4{
        void* t;  //0-7, 8 byte
        int b;    //8-11, 4 byte
                  //12-15, 4 byte alignment
        double** a = new double*[10]; //16-23, address 8 bytes
    };//24

    struct c5{
        int b[10];//0-39, 10*4 byte
        char a;   //40, 1 byte
                  //41-43 ,3 byte padding
    };//44

    cout<<sizeof (c)<<" "<<sizeof (c1)<<" "<<sizeof (c2)<<" "<<sizeof (c3)<<" "<<sizeof (c4)<<" "<<sizeof (c5)<<" "<<endl<<endl;//56

    //2.2
    struct X
    {
        short s; /* 2 bytes */
                /* 2 padding bytes */
        int   i; /* 4 bytes */
        char  c; /* 1 byte */
                /* 3 padding bytes */ //padding should be convnient for max type
    };
    struct Y
    {
        int   i; /* 4 bytes */
        char  c; /* 1 byte */
                /* 1 padding byte */
        short s; /* 2 bytes */
    };
    struct Z
    {
        int   i; /* 4 bytes */
        short s; /* 2 bytes */
        char  c; /* 1 byte */
                /* 1 padding byte */
    };
    cout<<sizeof(X)<<" "<<sizeof(Y)<<" "<<sizeof(Z)<<endl;
    
    //2.3
    X arr1[10];//10*12
    Y arr2[10];//10*8
    Z arr3[10];//10*8
    cout<<sizeof(arr1)<<" "<<sizeof(arr2)<<" "<<sizeof(arr3)<<endl;

    //2.4
    X* ptr1 = new X[10];
    Y* ptr2 = new Y[10];
    Z* ptr3 = new Z[10];
    cout<<sizeof(ptr1)<<" "<<sizeof(ptr2)<<" "<<sizeof(ptr3)<<endl;//sizeof(pointer). address length = 4 or 8 bytes
   
    return 0;
}