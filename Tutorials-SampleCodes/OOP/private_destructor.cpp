#include<iostream>
using namespace std;

class base{
private:
    int* ar;
    ~base()
    {
        delete[] ar;
    }
public:
    base(int s)
    {
        ar = new int[s];
    }
friend void f();
};
void f()
{
    base test(10);
}

int main()
{
f();
// base test(10);
return 0;
}