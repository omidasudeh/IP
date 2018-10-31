class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n - 1;
        int left = -1, right = -1;
        
        while (l < r) {
            int m = (l + r) / 2;
            if (A[m] == target) r = m;
            else if (A[m] > target) r = m - 1;
            else l = m + 1;
        }
        if (A[l] == target) left = l;
        
        l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (A[m] == target) l = m;
            else if (A[m] > target) r = m - 1;
            else l = m + 1;
        }
        if (A[r] == target) right = r;
        
        return vector<int>{left, right};
    }
};
