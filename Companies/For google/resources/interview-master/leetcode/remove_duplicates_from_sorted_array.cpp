class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        int last = A[0];
        int num = n;
        for (int i = 1; i < num; ++i) {
            if (A[i] == last) {
                num--;
                for (int j = i; j < num; ++j) {
                    A[j] = A[j + 1];
                }
                --i;
            }
            else last = A[i];
        }
        return num;
    }
};
