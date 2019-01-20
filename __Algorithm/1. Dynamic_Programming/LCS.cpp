/*
    Longest common subsequence
*/
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <gtest/gtest.h>
using namespace std;
# define max(a,b) (a>b)?a:b 
void print_helper(string& A, string& B,vector<vector<int>>& F, int i,int j, string& result){
    if(i>0 && j>0){
        if(A[i-1] == B[j-1]){
            result.push_back(A[i-1]);
            print_helper(A,B,F,i-1,j-1,result);
        }
        else if (F[i-1][j]>F[i][j-1])
        {
            print_helper(A,B,F,i-1,j,result);
        }
        else{
            print_helper(A,B,F,i,j-1,result);
        }
    }
}
string print(string& A, string& B,vector<vector<int>>& F, int i,int j){
    string reverse_result = "";
    print_helper(A,B,F,i,j,reverse_result);
    string result = "";
    while(reverse_result.size()>1){
        result.push_back(reverse_result.back());
        reverse_result.pop_back();
    }
    return result;
}
string LCS(string A, string B){
    int result = 0;
    int m = A.size()+1; // one extra as boundary 
    int n = B.size()+1; // one extra as boundary
    vector<vector<int>> F(m, vector<int>(n,0)); // boundary: the top row and left column equal zeros
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            if(A[i] == B[j]){
                F[i][j] = 1+F[i-1][j-1];
            }
            else{
                F[i][j] = max(F[i-1][j],F[i][j-1]);
            }
            cout<<F[i][j]<<" ";
        }
        cout<<endl;
    }
    result = F[m-1][n-1];
    return (print(A,B,F,m,n));
}

TEST(LCS,test1){
    string A = "abababa";
    string B = "bababa";
    ASSERT_EQ(LCS(A,B),"bababa");
}