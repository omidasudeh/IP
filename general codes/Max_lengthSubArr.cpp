#include<iostream>
#include<vector>
using namespace std;
class solution{
    public:
    void MLSA(vector<int>& a, int M)
    {
        int n = a.size();
        int gl = 0;
        vector< vector<int> > f(n+1,vector<int>(M+1,0));//f[n+1][M+1] = 0
        cout<<f.size()<<","<<f[0].size()<<endl;
        for(int i = 1; i<n+1;i++)
        {
            for(int p = 1;p<M+1;p++)
            {
                if(a[i-1]<=p)
                {
                    if(f[i-1][p]>(f[i-1][p-a[i-1]]+1))
                    {
                        f[i][p] = f[i-1][p]; 
                    }
                    else
                    {
                        f[i][p] = f[i-1][p-a[i-1]]+1;
                    }                    
                }
                else{
                    f[i][p] = 0;// convert to knap sack f[i-1][p];               
                }
                if(f[i][p]>gl)
                {
                   gl=f[i][p];
                }
            }
        }
        // for(int i = 0;i<n+1;i++)
        // {
        //     for(int j = 0;j<M+1;j++)
        //         cout<<f[i][j]<<",";
        //     cout<<endl;
        // }
        cout<<"max length subarray we can buy with $"<<M<<" is:"<<gl<<endl;


    }
};
int main()
{
    solution S;
    // int arr[] = {1,10,1,1};
    int arr[] = {5,1,1,1,20,1,1,1,2,1,6};
    vector<int> a( arr, arr + sizeof(arr) / sizeof(arr[0])); 
    int m = 5;
    S.MLSA(a,m);
    return 0;
}