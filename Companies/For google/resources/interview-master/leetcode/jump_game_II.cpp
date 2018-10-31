class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int farthest = 0;
        int nextfar = 0;
        int jumps = 0;
        int i = 0;
        while (nextfar < n - 1) {
            nextfar = farthest;
            ++jumps;
            for (int k = i; k <= farthest; ++k)
                nextfar = max(nextfar, k + A[k]);
            i = farthest + 1;
            farthest = nextfar;
        }
        return jumps;
    }
};
