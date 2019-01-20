#include <iostream>
using namespace std;
class private_destructor{
    private:
        int val;
        ~private_destructor(){;} // Note the private destructor
    public:
        private_destructor(int v):val(v){;}
        void print(){
            cout<<"the val is: "<<val<<endl;
        }
    friend class myfriend;
};
class myfriend{
    public:
        myfriend(int v){
            private_destructor* pd = new private_destructor(v);
            pd->print();
            delete pd; // the friend class can call the destructor
        }
};

int main(){
    myfriend fri(10); // hi five! this is working

    // private_destructor* pd = new private_destructor(10);
    // pd->print();
    // delete pd; //  !!!!NOTE: pd cannot call destructor here

    return 0;
}