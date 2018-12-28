#include "Queue.h"
#include <iostream>
#include <stdexcept>
using namespace std;
MyQueue::MyQueue(int s = 10):size(s){
    if(size>0){
        container = new int[size];
        // Note: The Q is in Empty State if both pointers are set to -1
        front = -1;
        rear = -1;
    }
    else
        throw(std::length_error("Queue size should be greater than 0"));
}
MyQueue::~MyQueue()
{
    if(size>0)
        delete [] container;
}
void MyQueue::insert(int item)
{
    if(!full())
    {
        if(empty())
            front = (front+1)%size;
        rear = (rear+1)%size;
        container[rear] = item;
    }
    else
        throw(std::overflow_error("Insertion to full queue"));
}
bool MyQueue::empty()
{
    return((front == -1) &&(rear == -1));
}
int  MyQueue::remove()
{
    int r = 0;
    if(!empty())
    {
        r = container[front];
        if(rear == front) // if only one element the Q reset to empty state
        {
            rear = -1; front = -1;
            return r;
        }            
        front = (front+1)%size;
        return r;
    }
    else throw(std::underflow_error("Removal from empty queue"));
}
bool MyQueue::full()
{
    return(((rear+1)%size) == front); 
}
