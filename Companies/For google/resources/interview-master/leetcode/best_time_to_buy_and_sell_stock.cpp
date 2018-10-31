class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int ans = 0;
        if (n == 0) return ans;
        int minp = prices[0];
        for (int i = 0; i < n; ++i) {
            if (prices[i] < minp) minp = prices[i];
            else if (prices[i] - minp > ans) ans = prices[i] - minp;
        }
        return ans;
    }
};
