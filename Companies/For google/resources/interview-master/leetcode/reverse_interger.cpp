class Solution {
public:
    int reverse(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int neg = 0;
        if (x < 0) {
            x = 0 - x;
            neg = 1;
        }
        int n = x % 10;
        while (x = x / 10) {
            n = 10 * n + x % 10;
        }
        if (neg) n = 0 - n;
        return n;
    }
};
