ass Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int farthest = 0;

        for (int i = 0; i < n; ++i) {
            if (i > farthest) return false;
            if (A[i] + i > farthest) farthest = A[i] + i;
        }
        if (farthest >= n - 1) return true;
        return false;
    }
};
