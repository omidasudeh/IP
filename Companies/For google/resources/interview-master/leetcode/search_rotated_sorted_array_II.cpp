class Solution {
public:
    bool search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n - 1;
        while (l < r && A[l] == A[r]) --r;
        while (l <= r) {
            int m = (l + r) / 2;
            if (A[m] == target) return true;
            if (A[m] >= A[l]) {
                if (target <= A[m] && target >= A[l]) r = m - 1;
                else l = m + 1;
            }
            else if (target >= A[m] && target <= A[r]) l = m + 1;
            else r = m - 1;
        }
        return false;
    }
};
