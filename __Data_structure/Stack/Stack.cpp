#include "Stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;
MyStack::MyStack(int s = 10):size(s){
    if(size>0){
        container = new int[size];
        // Note: The Q is in Empty State if both pointers are set to -1
        top = -1;
    }
    else
        throw(std::length_error("Stack size should be greater than 0"));
}
MyStack::~MyStack()
{
    if(size>0)
        delete [] container;
}
void MyStack::push(int item)
{
    if(!full())
    {    
        top++;
        container[top] = item;
    }
    else
        throw(std::overflow_error("stack is full"));
}

void MyStack::pop()
{
    if(!empty())
        top--;
    else
        throw(std::underflow_error("stack is empty"));
}
int  MyStack::peek()
{
    if(!empty())
        return container[top];
    else
        throw(std::underflow_error("stack is empty"));
}
bool MyStack::empty()
{
    return(top ==-1);
}
bool MyStack::full()
{
    return(top == size-1); 
}