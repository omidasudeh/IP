#ifndef MYSTACK_H
#define MYSTACK_H
class MyStack
{
  private:
    int *container;
    int size;
    int top;

  public:
    MyStack(int);
    ~MyStack();
    bool empty();
    bool full();
    void push(int);
    void pop();
    int peek();
};
#endif