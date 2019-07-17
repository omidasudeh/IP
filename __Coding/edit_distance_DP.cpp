/*
72. Edit Distance
Hard

Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


 */
class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            Define:
            let f[i][j] denote the min edit distance of a1a2...ai-1ai and b1b2...bi-1bj
            
            Recursion:
            f[i][j] = f[i-1][j-1] if a[i] == b[j]
            f[i][j] = min(f[i-1][j],  //add
                          f[i][j-1],  //remove    o.w.
                          f[i-1][j-1] //replave
                        )+1
                        
            Fill pattern:
                        i
                ------------>
                -------**--->
               j-------*+--->
                ------------>
            
            Goal:
            f[m][n]
            
            Boundary:
            f[0][j]=n
            f[i][0]=m
            f[0][0] = 0;
            
            Complexity:
            time:m*n
            space:m*n
            
            space can be improved to O(min(m,n)) by only keeping previous row

        */
        int m = word1.size();
        int n = word2.size();
        if(m == 0)
            return n;
         if(n == 0)
            return m;
        vector<vector<int>> f(m+1,vector<int>(n+1,0));
        
        //set boundary
        for(int i = 0;i<=m;i++){
            f[i][0] = i;
        }
        for(int j = 0;j<=n;j++)
            f[0][j] = j;
        
        f[0][0] = 0;
        // set recursion
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    f[i][j] = f[i-1][j-1];
                else{
                    f[i][j] = min(1+f[i-1][j],  //add
                                min(1+f[i][j-1],  //remove    o.w.
                                    1+f[i-1][j-1]) //replave
                        );
                }
            }
        }
        // for(int i = 0;i<=m;i++){
        //     for(int j = 0;j<=n;j++){
        //         cout<<f[i][j]<<"\t";
        //     }
        //     cout<<endl;
        // }
        
        return f[m][n];
    }
        int minEditDistanceLinearSpace(string word1, string word2) {
        /*      
            space can be improved to O(min(m,n)) by only keeping previous row
        */
        int m = word1.size();
        int n = word2.size();
        if(m == 0)
            return n;
         if(n == 0)
            return m;
        if(m<n){
            swap(m,n);
            swap(word1,word2);
        }
        vector<int> f(vector<int>(n+1,0));
        
        //set boundary
        for(int i = 0;i<=n;i++){
            f[i] = i;
        }
        // set recursion
        for(int i = 1;i<=m;i++){

            f[0] = i;
            int fi_1j_1 = i-1;
            for(int j = 1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    int t = f[j];
                    f[j] = fi_1j_1;
                    fi_1j_1 = t;
                }
                else{
                    int t = fi_1j_1;
                    fi_1j_1 = f[j];
                    f[j] = min(1+f[j],  //add
                                min(1+f[j-1],  //remove    o.w.
                                    1+t) //replave
                        );
                }
            }

        }
        return f[n];
    }
};
