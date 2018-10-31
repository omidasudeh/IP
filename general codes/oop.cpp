/*
practice oop concepts
https://www.tutorialspoint.com/cplusplus/cpp_object_oriented.htm
- Encapsulation: putting the data and relevant functions in the same place

- Data Abstraction: exposing only the essential information to the outside world

- Inheritence: to reuse the properties and functionality of a base class in the derived class. 
	{class derived-class: access-specifier base-class}
	Type of Inheritance(access) (same class, derived class, outside): public(yes,yes,yes), private(yes,no,no), protected(yes, yes, no) 

- polymorphism: same function that operates differently. 
	- virtual fucntion: https://www.tutorialspoint.com/cplusplus/cpp_polymorphism.htm
		Pure virtual fucntion: if the virtual function does not have a meaning in the base class (only definable in the derived class) we can set its body to nothing: virtual int area() = 0;
	- Overloading:  is an example of polymorphism
		fucntion overoading:

		operator overloading:
			Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for the operator being defined. Like any other function, an overloaded operator 				has a return type and a parameter list.
			// Overload + operator to add two Box objects.
		      Box operator+(const Box& b) {
			 Box box;
			 box.length = this->length + b.length;
			 box.breadth = this->breadth + b.breadth;
			 box.height = this->height + b.height;
			 return box;
		      }
			int &operator[](int i) {
				 if( i > SIZE ) {
				    cout << "Index out of bounds" <<endl; 
				    // return first element.
				    return arr[0];
				 }
				 
				 return arr[i];
			      }

		      // overloaded prefix ++ operator
		      Time operator++ () {
			 ++minutes;          // increment this object
			 if(minutes >= 60) {
			    ++hours;
			    minutes -= 60;
			 }
			 return Time(hours, minutes);
		      }
		      
		      // overloaded postfix ++ operator
		      Time operator++( int ) {
		      
			 // save the orignal value
			 Time T(hours, minutes);
			 
			 // increment this object
			 ++minutes;                    
			 
			 if(minutes >= 60) {
			    ++hours;
			    minutes -= 60;
			 }
			 
			 // return old original value
			 return T; 
		      }
			void operator = (const Distance &D ) { 
				 feet = D.feet;
				 inches = D.inches;
			      }

		      friend ostream &operator<<( ostream &output, const Distance &D ) { 
			 output << "F : " << D.feet << " I : " << D.inches;
			 return output;            
		      }

		      friend istream &operator>>( istream  &input, Distance &D ) { 
			 input >> D.feet >> D.inches;
			 return input;            
		      }

- Friend Functions : A friend function is permitted full access to private and protected members of a class.
	class Box {
	   double width;
	   
	   public:
	      friend void printWidth( Box box );
	      void setWidth( double wid );
	};

	// Member function definition
	void Box::setWidth( double wid ) {
	   width = wid;
	}

	// Note: printWidth() is not a member function of any class.
	void printWidth( Box box ) {
	    Because printWidth() is a friend of Box, it can
	   directly access any member of this class 
	   cout << "Width of box : " << box.width <<endl;
	}
	 
	// Main function for the program
	int main() {
	   Box box;
	 
	   // set box width without member function
	   box.setWidth(10.0);
	   
	   // Use friend function to print the wdith.
	   printWidth( box );
	 
	   return 0;
	}


*/

#include<iostream>
using namespace std;

class shape{
protected:
	int width;
	int height;
public:
	shape(int w = 0, int h = 0):width(w), height(h){}
	virtual int area() = 0;//pure virtual function. It is not defined for the base fucntion, but only declared here to be defined in the defined derived classes
};
class rectangle:public shape{
	public:
		rectangle(int w = 0, int h = 0):shape(w,h){}
		int area()
		{
			return width*height;
		}
};
class triangle: public shape{
public:
		triangle(int w = 0, int h = 0):shape(w,h){}
		int area()
		{
			return (width*height)/2;
		}
};
class myarray{
	private:
		int* container;
		int size;
	
	public:
	myarray(int s, int* arr):size(s){
		container = new int[size];
		for(int i = 0;i<size;i++)
			container[i] = arr[i];
	}
	~myarray()
	{
		delete [] container;
	}
	int getSize()
	{
		return size;
	}
	int& operator[](int i)
	{
		return container[i];
	}
	myarray operator+ (myarray &arr)
	{
		int max_size = (arr.getSize()>this->size)?arr.getSize():this->size;
		int min_size = (arr.getSize()<this->size)?arr.getSize():this->size;
		int* res = new int[max_size];
		for(int i = 0;i<max_size;i++)
		{
			if(i<=min_size)
				res[i] = container[i]+arr[i];
			else
			{
				if(arr.getSize() == min_size)
					res[i] = container[i];
				else
					res[i] = arr[i];
			} 
		}
		myarray myres (max_size, res);
		return myres;
	}
	void print(ostream &output) const
	{
		cout<<size<<endl;
		for(int i =0; i<size;i++)
			output << container[i]<<",";
	}
	friend ostream &operator<<( ostream &output, const myarray  &arr ) { 
		arr.print(output);
		return output;            
	}
};
int main(int argc, char** argv)
{
	shape* sr, *st;
	rectangle r(3,5);
	triangle t(3,5);
	cout<<"rect area:"<<r.area()<<" tri area:"<<t.area()<<endl;
	sr = &r;
	st = &t;
	cout<<"rect area:"<<sr->area()<<" tri area:"<<st->area()<<endl;
	/*
	output:
		rect area:15 tri area:7
		rect area:15 tri area:7
	*/

	int A[3] = {2,3,5};
	myarray(3,A);
	cout<<A;
	int B[5] = {1,2,3,4,5};
	myarray(3,A);
return 0;
}
