/* 
- this is to demonstrate restricting constructor for all but the friends
  * in this example we restrict the constructor in the form of base(int v) to friends only;
  * but we allow the default constructor for all 
*/
#include <iostream>
using namespace std;
class base{
    private:
        int val;
        base(int v):val(v){;} // friend class can instantiate from base
    public:
        base(){;} // here default constructor is not restricted
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
    base b;
    myfriend mf;
    return 0;
}