#include <iostream>
using namespace std;
class complex{
    private: 
        int real;
        int imag;
    public:
        complex(int r, int i):real(r), imag(i){;}
        ~complex(){;}
        complex operator= (const complex & right){
            this->real = right.real;
            this->imag = right.imag;
        }

// IO operators ==> return ostream& or istream&
        friend ostream& operator<<(ostream& out, const complex & c){
            out<<"\nreal: "<<c.real<<"\nimaginary: "<<c.imag<<endl;
            return out;
        }

        friend istream& operator>>(istream& in, complex& c){
            cout<<"enter real:";
            in>>c.real;
            cout<<"enter imaginary:";
            in>>c.imag;
            return in;
        }

// assignment
        complex& operator=(complex& c1){
            real = c1.real;
            imag = c1.imag;
            return *this;
        }


// binary operators ==> return by value
        complex operator+(complex& c1){
            complex r(*this);
            r.real = real+c1.real;
            r.imag = imag+c1.imag;
            return r;
        }

        complex operator+=(complex& c1){
            real += c1.real;
            imag += imag+c1.imag;
            return *this;
        }
//unary
        complex & operator++(int){//complex++
            real++;
            imag++;
            return *this;
        }
        complex & operator++(){//complex++
            real = real+1;
            imag = imag+1;
            return *this;
        }

};
int main(){
    complex c1(10,2);
    cin>>c1;

    complex c2(10,2);
    cin>>c2;
    c1+=c2;
    cout<<(c1+c2);
    cout<<c1;
    c1++;
    cout<<c1;

    return 0;
}