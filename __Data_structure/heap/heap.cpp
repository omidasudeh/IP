#include<iostream>
#include "heap.h"
void Heap::buildheap()
{
    int p = (*heap).size()/2;//all leaves follow heap property; start from level h-1
    for(int i = p;i>=0;i--)
        heapify(i);
} 
void Heap::heapify(int i)
{
    int size = (*heap).size();
    if(size>0)
    {
        int first_child = 2*i+1;
        if(first_child<size)
        {
            int min_child = first_child;// assume the first child is the min child
            int sec_child = 2*i+2;
            if(sec_child<size)
                if((*heap)[sec_child]<(*heap)[min_child])
                    min_child = sec_child;
            if((*heap)[i]>(*heap)[min_child])
            {
                int t = (*heap)[i];
                (*heap)[i] = (*heap)[min_child];
                (*heap)[min_child] = t;
                heapify(min_child);
            }
        } 
    }
}
Heap::Heap(vector<int>* H)
{
    heap = H;
    buildheap();
}
int Heap::delete_min()
{
    if((*heap).size()>0){
        int min = (*heap)[0];
        (*heap)[0] = (*heap)[(*heap).size()-1];//replace root of heap with the last element
        (*heap).pop_back();//remove the last element
        // cout<<"here\n";
        heapify(0);
        return min;
    }
}   
void Heap::insert(int k)
{
    (*heap).push_back(k);
    int i = (*heap).size()-1;
    while((*heap)[i]<(*heap)[i/2]&&i>=0)
    {
        int t = (*heap)[i/2];
        (*heap)[i/2] = (*heap)[i];
        (*heap)[i] = t;
        i /= 2;
    }
}
