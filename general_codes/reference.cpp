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
class ref
{
    private:
        vector<int>* C;
    public:
        ref(vector<int>* A)
        {
            C = A;
            (*C)[0]=0;
        }

};
int  main()
{

    // pair<int, int> p;
    // p  = pair<int,int>(2,3);
    // cout<<p.first<<","<<p.second<<endl;
    vector<int> X(5,100);// a vector of length 5 init to 100 in all cells
    print(X);
    ref a(&X);
    print(X);



    return 0;
}