/*
- a derived class will access all non-private (public and protected) elements of the base class
- an outside class can only access the public elements of a class
- a derived class do not inherit the constructors/ copy of constructors and destructors of the base class.
- a derived class do not inherit the overloaded operators of the base class.
- a derived class do not inherit friend classes of the base class.
- when deriving a class as public then public members of the base become public member of the derived class and protected members of the base class become protected members of the derived class.
- when deriving a class as Protected then public and protected members of the base become protected.
- when deriving a class as private then public and protected members of the base become private.
*/

#include<string>
#include<iostream>
using namespace std;
class Person{
    // private: 
    //     string name;
    //     int age;
    public:
        Person()
        {
            cout<<"Person Constructor!"<<endl;
        }
        ~Person(){
            cout<<"Person Destructor!"<<endl;
        }
};

class Student: public Person{
    // private:

    public:
        Student()
        {
            cout<<"Student Constructor!"<<endl;
        }
        ~Student()
        {
            cout<<"Student Destructor!"<<endl;
        }

};
class Professor: public Person{
    // private:

    public:
        Professor()
        {
            cout<<"Professor Constructor!"<<endl;
        }
        ~Professor()
        {
            cout<<"Professor Destructor!"<<endl;
        }
};
int main()
{
    Person* p = new Student();// what is the output? 
    delete(p);
    return 0;
}