class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        double num = 1;
        for (double i = 1; i <= n; ++i) {
            num *= double(n + i) / i;
        }
        num /= (n + 1);
        return (int)num;
    }
};
