class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = num.size();
        sort(num.begin(), num.end());
        vector<vector<int>> res = vector<vector<int>>();
        vector<int> quadruplet(4);
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && num[i] == num[i - 1]) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && num[j] == num[j - 1]) continue;
                int l = j + 1, r = n - 1;
                int goal = target - num[i] - num[j];
                while (l < r) {
                    if (num[l] + num[r] == goal) {
                        quadruplet[0] = num[i], quadruplet[1] = num[j];
                        quadruplet[2] = num[l], quadruplet[3] = num[r];
                        res.push_back(quadruplet);
                        ++l, --r;
                        while (l < r && num[l] == num[l - 1]) ++l;
                        while (l < r && num[r] == num[r + 1]) --r;
                    }
                    else {
                        while (l < r && num[l] + num[r] < goal) ++l;
                        while (l < r && num[l] + num[r] > goal) --r;
                    }
                }
            }
        }
        return res;
    }
};
