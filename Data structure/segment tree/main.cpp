#include "segment_tree.h"
#include <iostream>
using namespace std;
int main()
{
    //================= generate input array ==================
    int size = 5;
    int * data = new int[size];
    for(int i = 0;i<size;i++)
    {
        data[i] = i;
        cout<<data[i]<<",";
    }
    cout<<endl;
    //================ build segment tree =====================

    Segment_tree seg_tree(data, size);

    //================ range query ============================
    int result = seg_tree.range_query(0,3);
    seg_tree.dump_tree();
    cout<<"result: "<<result<<endl;
    
    return 0;
}