#ifndef HEAP_H
#define HEAP_H
#include <vector>
using namespace std;
class Heap{
    private:
        vector<int>* heap;
        void buildheap();
        void heapify(int);
    public:
    Heap(vector<int>*);
    // ~Heap();//vector destructor handles this
    int delete_min();  
    void insert(int k);
};
#endif