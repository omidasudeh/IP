class Solution {
public:
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int max = 0;
        int cmax = 0;
        int imax = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (cmax + A[i] > 0) {
                cmax = cmax + A[i];
                if (cmax > max) max = cmax;
            }
            else cmax = 0;
            if (A[i] > imax) imax = A[i];
        }
        if (!max) return imax;
        return max;
    }
};
