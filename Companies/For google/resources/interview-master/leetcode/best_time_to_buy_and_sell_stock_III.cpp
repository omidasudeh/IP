class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> right(n, 0);
        int ans = 0;
        int maxp = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            right[i] = max(right[i + 1], maxp - prices[i]);
            maxp = max(maxp, prices[i]);
            ans = max(ans, right[i]);
        }
        int minp = prices[0];
        for (int i = 0; i < n - 1; ++i) {
            ans = max(ans, prices[i] - minp + right[i + 1]);
            minp = min(prices[i], minp);
        }
        return ans;
    }
};
