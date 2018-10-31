class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int num = n;
        int t = 0;
        for (int i = 0; i < num; ++i) {
            if (A[i] == elem) {
                t = 1;
                while (i + t < num && A[i + t] == elem) ++t;
                num -= t;
                for (int j = i; j < num; ++j) {
                    A[j] = A[j + t];
                }
                --i;
            }
        }
        return num;
    }
};
