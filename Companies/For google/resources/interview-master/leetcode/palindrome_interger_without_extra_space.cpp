class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        int d = x;
        int t = 1;
        while (d = d / 10) ++t;
        if (t == 1) return true;
        d = x;
        int n = 0;
        for (int i = 0; i < t / 2; ++i) {
            n = 10 * n + d % 10;
            d = d / 10;
        }
        if (t & 1) d = d / 10;
        if (d == n) return true;
        return false;
    }
};
