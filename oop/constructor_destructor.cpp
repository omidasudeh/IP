/*
Goal: Demonstrate the following:
- base and derived class syntax
- member initialization list
- base and derived constructors initialtion
- constructor order
- destructor order
- virtual destructor: if not base virtual destructor, undefined behavior likely the derived destructor won't run!
- use the inhirited base function print in the derived function
- copy constructor
- private copy constructor
*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Person{
    private:
        string name;
        string* seen_movies; 
        int seen_movies_num;
        /* private copy constructor to avoid default copy constructor and avoid runtime segmentation fault*/
        // Person(const Person &p):seen_movies_num(p.seen_movies_num), name(p.name){//copy constructor
        //     // seen_movies = new string[seen_movies_num];
        //     cout<<"Person: "<<name<<" copy Constructor!"<<endl;
        // }
    public:
        Person(string nm, int SMN):seen_movies_num(SMN), name(nm){
            seen_movies = new string[seen_movies_num];
            cout<<"Person: "<<name<<" Constructor!"<<endl;
        }
        Person(const Person &p):seen_movies_num(p.seen_movies_num), name(p.name){//copy constructor
            seen_movies = new string[seen_movies_num];
            cout<<"Person: "<<name<<" copy Constructor!"<<endl;
        }
        void print()
        {
            cout<<"############## Person info ################"<<endl;
            cout<<"Person name:"<<name<<endl;
            cout<<"Number of seen movies:"<<seen_movies_num<<endl;
            cout<<"seen movies:"<<endl;
            for(int i = 0 ;i<seen_movies_num;i++)
                cout<<i<<". "<<seen_movies[i]<<endl;
        }
        virtual ~Person(){
            delete[] seen_movies;
            cout<<"Person "<<name<<" Descructor!"<<endl;
        }
};
class Student: public Person{
    private:
        int stID;
        int num_courses_taken;
        string * courses;
    public:
        Student(string nm = "", int SMN = 0, int id = -1, int nc = 0):Person::Person(nm,SMN),num_courses_taken(nc){
            courses = new string[num_courses_taken];
            cout<<"Student "<<stID<<" Constructor!"<<endl;
        }
        void print()
        {
            cout<<"-------------- Student info -----------------"<<endl;
            Person::print();
            cout<<"Student ID: "<<stID<<endl;
            cout<<"number of courses taken: "<<num_courses_taken<<endl;
            for(int i = 0 ;i<num_courses_taken;i++)
                cout<<i<<". "<<courses[i]<<endl;
        }
        ~Student(){
            delete[] courses;
            cout<<"Student "<<stID<<" Descructor!"<<endl;
        }
};
int main()
{    
    Student * s = new Student("omid",3,0,10);
    Person *p = s;
    s->print();
    p->print();// not virtual so the base version is run
    delete p;// virtual destructor makes sure that this will run derived and based destructors
    // delete s;

    //==============
    Person p1("Ali",3);
    Person p2(p1);
    p2.print();

    return 0;
}