#include <iostream>
using namespace std;
class mytype{
    private:
        int* container;
        int size;
    public:
        mytype(int s):size(s){
            container = new int[size];
        }
        mytype(const mytype& t):size(t.size){//creating copy constructor
            cout<<"copy constructor called\n";
            container = new int[size];
            for(int i = 0;i<size;i++)
                container[i] = t.container[i];
        }
        void seti(){
            for(int i = 0;i<size;i++)
                container[i] = i;
        }
        void set0(){
            for(int i = 0;i<size;i++)
                container[i] = 0;
        }
        void set1(){
            for(int i = 0;i<size;i++)
                container[i] = 1;
        }
        void print(){
            for(int i = 0;i<size;i++)
                cout<<container[i]<<',';
            cout<<endl;
        }
        ~mytype(){
            delete [] container;
        }
};
void func(mytype mt){
    mt.print();
}
int main(){
    mytype t1(10);
    t1.set1();
    mytype t2(t1);
    t2.seti();
    func(t1);
    func(t2);

    return 0;
}