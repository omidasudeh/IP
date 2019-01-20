#include <iostream>
using namespace std;
class base{
    private:
        int val;
        base(int v):val(v){;} // friend class can instantiate from base
    public:
        void print(){
            cout<<"val is: "<<val<<endl;
        }
    friend class myfriend;
};
class myfriend{
    public:
        myfriend(){
            base b(12);
            b.print();
        }
};
int main(){
    // base b(12); // private constructor prohibits instantiation except fot friends
    myfriend mf;
    return 0;
}