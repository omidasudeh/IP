// test for static variables
#include<stdlib.h>
#include<stdio.h>
#include "linker.h"
#include <string>
#include <iostream>
using namespace std;
int* shuffle(int n){
	srand(time(0));
    int * A = new int[n];
	for(int i = 0;i<n;i++) A[i] = i;
    for(int i = 0;i<n;i++)
    {
        int r = rand()%(n-i)+i;
		int t = A[i];
        A[i] = A[r];
		A[r] = t;
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return A;
}
int reverse(int a){
	int r = 0;
	while(a>0){
		int d0 = a&0xf;a=a>>4;
		r = (r<<4)|d0;
	}return r;
}
string strReverse(string s)
{
    string result = "";
    int i = s.size()-1, j=s.size()-1;
    while(j>=0){
        if(s[j]==' '){
            string word = s.substr(j+1, i-j);
            i = j-1;
			result+=(word+" ");        
        }
        j--;        
    }
	result+=(s.substr(0,i+1));
	return result;
}
int main()
{
// {

// //############################ test static 
// 	{
// 		static int v = 100; // static variable has local scope. but its lifetime is till the end of program
// 		goto B;
// A:		printf("%d",v);// so it is not deleted by going out of scope. and keeps its value. if it was not static. going out of scope it would be deleted and we could not print it. 
// 		goto C;	
// 	}
// B:	printf("out of scope");
// 	goto A;
// C:	printf("end static test\n================\n");
// 	//printf("%d",v);//scope of v is local. so this will generate not declared error.
// //############################ test extern
// 	extern int v1;
// 	printf("%d\n",v1);// so it is not deleted by going out of scope. and keeps its value. if it was not static. going out of scope it would be deleted and we could not print it. 
// //############################ 
// 	// shuffle(10);
// 	// int a = 0x123;
// 	// cout<<"a= "<<hex<<a<<endl;
// 	// cout<<"reverse of "<<a<<" is "<<reverse(a)<<endl;
// 	// cout<<"=================\n";
// 	// string s = "            who  are you    omid    ";
// 	// cout<<dec<<strReverse(s)<<endl;



	//#################
	long long* a ;
	a = (long long*) malloc(32);
	for(int i = 0 ; i<4;i++)
	{
		cout<<a<<endl;
		a++;

	}
	return 0;
}
