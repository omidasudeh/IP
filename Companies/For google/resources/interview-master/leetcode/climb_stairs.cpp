class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> way(n + 1, 0);
        way[0] = 1;
        way[1] = 1;
        for (int i = 2; i <= n; ++i) {
            way[i] = way[i - 1] + way[i - 2];
        }
        return way[n];
    }
};