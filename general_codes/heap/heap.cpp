#include<iostream>
#include<vector>
using namespace std;
void print(vector<int>& A)
{
    for(int i = 0;i<A.size();i++)
    {
        cout<<A[i]<<",";
    }
    cout<<endl;
}
class Heap{
    private:
        vector<int>* heap;
        void buildheap(int i)
        {
            int size = (*heap).size();
            if(size == 0) return;
            int first_child = 2*i+1;
            if(first_child<size)//if has the first child
            {
                int sec_child = 2*i+2;
                buildheap(first_child);
                if(sec_child<size)//if has the second child
                    buildheap(sec_child);                    
                heapify(i);
            }
        } 
        void heapify(int i)
        {
            // cout<<"h0\n";
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
            // cout<<"h1\n";
        }
    public:
    Heap(vector<int>* H)
    {
        heap = H;
        buildheap(0);
    }
    int delete_min()
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
    void insert(int k)
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
};
int  main()
{
    vector<int> X = {7,8,3,2,4,5,6};
    print(X);
    Heap myheap(&X);
    print(X);
    for(int i = 0;i<6;i++){
        cout<<myheap.delete_min()<<endl;
        print(X);
    }
    for(auto e:X)
        myheap.insert(e);
    print(X);
    return 0;
}