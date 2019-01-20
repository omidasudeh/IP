#include <iostream>
using namespace std;
/*
 * virtual function
 * virtual pure function and abstract class
 * virtual destructor
*/
class shape{
    private:
        int size;// each shape has a specific container and size is its size
    public:
        int get_size(){
            return size;
        }
        shape(int s):size(s){;}
        virtual float Area() = 0; //pure function makes the class abstract
        virtual ~shape(){
            cout<<"shape destructor\n";
        }
};

class circle: public shape{
    private:
        float radious;
        int* nums;  // suppose each circle has a array of integers inside
    public:
        circle(float r, int s = 1):radious(r), shape::shape(s){
            nums = new int[get_size()];
        }
        float Area(){ return 3.141592*radious*radious;}
        ~circle(){
            cout<<"circle destructor\n";
            delete [] nums;
        }
};

class triangle: public shape{
    private:
        float width;
        float height;
        char* name; 
    public:
        triangle(float w,float h, int s):shape::shape(s),width(w), height(h){
            name = new char[get_size()];
        }
        float Area(){ return width*height/2;}
        ~triangle(){
            cout<<"triangle destructor\n";
            delete [] name;
        }
};
int main(){

    shape* ptr = new triangle(10, 10, 20);
    cout<<"area is "<<ptr->Area()<<endl;
    delete ptr;// expect triangle destructor

    return 0;
}