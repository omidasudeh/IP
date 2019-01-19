#include <iostream>
using namespace std;
class base{
    private:
        int A;
    public:
        base(int a):A(a){;}
        void squared(){
            cout<<A*A<<endl;
        }
    friend class myfriend;
    friend void myfunc(base);
};
class derived:public base{ //3. public inheritence: derived inherit public and protected
    private:
        int B;
    public:
        derived(int a, int b = 0):base::base(a), B(b){;} //<== base class is initialized using "member initializer list "
};

// class derived1:public base{
//     private:
//         int C;
//     public:
//         derived1(int a, int c){ 
                               // 2.a.i derived do not inherit constructor
//             base::base(a);  // <=== base class initiation cannot be deferred instead it should be initiated by "member initializer list"
//             c = C;
//         }
// };

class myfriend{
    public:
        myfriend(int c = 20){
            base b(15);
            derived d3(30);
            b.A = c; //1.a a friend class that can access all private, public and protected
            cout<<b.A<<endl;
            cout<<d3.A<<endl;
            // cout<<d3.B<<endl; // 2.a.c derived does not inherit friends 
        }
};
void myfunc(base b){
    cout<<b.A<<endl;
}

int main(){
    base b(5);
    b.squared();//An outside class can only access the public elements 

    // default initialization seems like overloading but there is no overloading
    derived d(10);
    derived d1(10,5);

    d.squared(); // A derived class will access all non-private (public and protected) elements of the base class
    
    myfunc(b); // friend function can access all (even private)

    myfriend fri(50);
return 0;
}