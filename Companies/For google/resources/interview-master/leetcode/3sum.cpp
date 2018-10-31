class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int>> res = vector<vector<int>>();
        vector<int> t(3);
        int n = num.size();
        sort(num.begin(), num.end());
        int l = 0, r = n - 1;
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            t[0] = num[i];
            int target = 0 - t[0];
            int l = i + 1, r = n - 1;
            while (l < r) {
                if (num[l] + num[r] == target) {
                    t[1] = num[l], t[2] = num[r];
                    res.push_back(t);
                    ++l, --r;
                    while (l < r && num[l] == num[l - 1]) ++l;
                    while (l < r && num[r] == num[r + 1]) --r;
                }
                while (l < r && num[l] + num[r] < target) ++l;
                while (l < r && num[l] + num[r] > target) --r;
            }
        }
        return res;
    }
};
