class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n < 2) n; 
        int time = 0;
        int lastnum = A[0];
        int t;
        for (int i = 1; i < n; ++i) {
            if (A[i] == lastnum) {
                if (time < 1) ++time;
                else {
                    t = 1;
                    while (i + t < n && A[i + t] == A[i]) ++t;
                    n = n - t;
                    for (int j = i; j < n; ++j) {
                        A[j] = A[j + t];
                    }
                    time = 0;
                    i--;
                }
            }
            else {
                lastnum = A[i];
                time = 0;
            }
        }
        return n;
    }
};