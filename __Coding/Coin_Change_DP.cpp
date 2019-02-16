/*
322. Coin Change
Medium

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
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        sort(coins.begin(), coins.end());
        if(amount <coins[0])
            return -1;
        vector<int>F(amount+1,0);
        for(int m=coins[0];m<F.size();m++){
            int min = INT_MAX;
            for(int i = 0;i<coins.size() && m>=coins[i];i++ ){
                if(coins[i]==m){
                    min = 1;
                    break;
                }
                else if(F[m-coins[i]]>0 && F[m-coins[i]]+1<min)
                    min = F[m-coins[i]]+1;
            }
            if(min<INT_MAX && min!=0)
                F[m] = min;
            else
                F[m] = -1;
        }
        return F[amount];
     }
};