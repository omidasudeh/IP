#include <stdio.h>  

struct A1      { A1(){printf("A1 constructor!\n");}  ~A1() { printf("A1 dtor\n"); } };  
struct A2 : A1 { A2(){printf("A2 constructor!\n");} ~A2() { printf("A2 dtor\n"); } };  
struct A3 : A2 { A3(){printf("A3 constructor!\n");} ~A3() { printf("A3 dtor\n"); } };   

struct VA1      { VA1(){printf("VA1 constructor!\n");} virtual ~VA1() { printf("VA1 dtor\n"); } };  
struct VA2 : VA1 { VA2(){printf("VA2 constructor!\n");}virtual ~VA2() { printf("VA2 dtor\n"); } };  
struct VA3 : VA2 { VA3(){printf("VA3 constructor!\n");}virtual ~VA3() { printf("VA3 dtor\n"); } };  
// struct A1      { virtual ~A1() { printf("A1 dtor\n"); } };  
// struct A2 : A1 { virtual ~A2() { printf("A2 dtor\n"); } };  
// struct A3 : A2 { virtual ~A3() { printf("A3 dtor\n"); } };  
  
struct B1      { ~B1() { printf("B1 dtor\n"); } };  
struct B2 : B1 { ~B2() { printf("B2 dtor\n"); } };  
struct B3 : B2 { ~B3() { printf("B3 dtor\n"); } };  
  
int main() {  
    A3 * a = new A3;// A1()==>A2()==>A3()
    delete a;//~A3()==>~A2()==>~A1()
    
    printf("******************\n");
    A1 * a1 = new A3;  
    delete a1;  
    printf("\n");

    printf("******************\n");
    VA1 * va = new VA3;  
    delete va;  
    printf("\n");  
  
//    B1 * b = new B3;  
//    delete b;  
//    printf("\n");  
  
//    B3 * b2 = new B3;  
//    delete b2;  
}