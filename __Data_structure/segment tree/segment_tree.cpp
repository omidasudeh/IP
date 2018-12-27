#include "segment_tree.h"
#include <iostream>
using namespace std;
int Segment_tree::Operation(int op1, int op2)
{
    /* Define the aggregate operation here. e.g.: sum, min, max, xor,...*/
    return op1+op2;
    //return (op1<op2)?op1:op2;//min
    //return (op1<op2)?op1:op2;//max
}
Segment_tree::Segment_tree(int* data, int s):N(s)
{
    // builds the segment tree given an array of integers
    tree = new int[2*N];
    for(int i=0;i<N;i++)
        tree[i+N]= data[i];
    for(int i = N-1; i>0;i--)
        tree[i] = Operation(tree[2*i],tree[2*i+1]);
}
bool Segment_tree:: update_point(int index, int value)
{
    return true;
}
int Segment_tree::range_query(int left, int right)
{
    int result = 0;//this is for sum
    //int result = -infinity;//this is for min

    left+=N;right+=N;//point to the range over the leaves
    while(left<right)
    {
        if(left%2)//if left is odd or left is the index of right child
        {
            result+=tree[left];
            left++;
        }
        if(right%2)// if right is odd or right is the index of right child
        {
            right--;
            result+=tree[right];
        }
        left/=2;
        right/=2;
    }
    return result;
}
void Segment_tree::dump_tree()
{
    cout<<"Segment tree: ";
    for(int i=1;i<2*N;i++)
    {
        cout<<tree[i]<<",";
    }
    cout<<endl;
}
Segment_tree::~Segment_tree()
{
    delete[] tree;
}
