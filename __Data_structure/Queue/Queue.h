#ifndef MYQUEUE_H
#define MYQUEUE_H
class MyQueue
{
  private:
    int *container;
    int size;
    int front;
    int rear;

  public:
    MyQueue(int);
    ~MyQueue();
    bool empty();
    bool full();
    void insert(int);
    int remove();
};
#endif