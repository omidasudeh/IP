/*
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Note:
You may assume that you have an infinite number of each kind of coin.

*/

#define min(a,b) (((a)<(b))?(a):(b))
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> F (coins.size()+1,vector<int>(amount+1,0));
        for(int i = 1;i<F.size();i++){
            for(int m = 1;m<F[0].size();m++){
                if(m%i==0){
                    F[i][m] = m/i;
                }
                else if(coins[i-1]<=m){
                    F[i][m] =min(1+ F[i-1][m-coins[i-1]],F[i-1][m]);
                }
                else{
                    F[i][m] = F[i-1][m]; 
                }
                cout<<F[i][m]<<"\t";
            }
            cout<<endl;
        }
        return F[F.size()-1][amount];
     }
};