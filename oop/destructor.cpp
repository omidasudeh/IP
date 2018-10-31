/*

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
    public:
        Person(string nm, int SMN):seen_movies_num(SMN), name(nm){
            seen_movies = new string[seen_movies_num];
            cout<<"Person Constructor!"<<endl;
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
            cout<<"Person Descructor!"<<endl;
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
            cout<<"Student Constructor!"<<endl;
        }
        void print()
        {
            Person::print();
            cout<<"-------------- Student info -----------------"<<endl;
            cout<<"Student ID: "<<stID<<endl;
            cout<<"number of courses taken: "<<num_courses_taken<<endl;
            for(int i = 0 ;i<num_courses_taken;i++)
                cout<<i<<". "<<courses[i]<<endl;
        }
        ~Student(){
            delete[] courses;
            cout<<"Student Descructor!"<<endl;
        }
};
// class Professor: public Person{
//     private:
//         int ProfID;
//     public:
//         Professor(int id):ProfID(id)
//         {

//         }
//         ~Professor()
//         {

//         }
// };


int main()
{
    
    Student * s = new Student("omid",3,0,10);
    Person *p = s;
    s->print();
    // p->print();

    delete p;
    // delete s;
    return 0;
}