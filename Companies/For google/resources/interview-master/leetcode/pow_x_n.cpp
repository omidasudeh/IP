class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 1.0;
        if (n > 0) return fastexp(x, n);
        else return 1.0 / fastexp(x, -n);
    }
    
    double fastexp(double x, int n) {
        double ans = 1.0;
        while (n) {
            if (n & 1) ans *= x;
            x *= x;
            n /= 2;
        }
        return ans;
    }
};
