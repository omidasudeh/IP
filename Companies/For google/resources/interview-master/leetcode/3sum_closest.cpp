class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cls = target + INT_MAX;
        int n = num.size();
        sort(num.begin(), num.end());
        for (int i = 0; i < n - 2; ++i) {
            int l = i + 1, r = n - 1;
            int a = num[i];
            while (l < r) {
                if (abs(num[l] + num[r] + a - target) < abs(cls - target)) {
                    cls = num[l] + num[r] + a;
                }
                if (num[l] + num[r] + a <= target) ++l;
                else if (num[l] + num[r] + a > target) --r;
            }
        }
        return cls;
    }
};
