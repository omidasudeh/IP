class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = strs.size();
        string r = "";
        int t = 0;
        bool check = true;
        if (n == 1) return strs[0];
        int minsize = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int len = strs[i].length();
            minsize = min(minsize, len);
        }
        if (n == 0) return r;
        while (t < minsize) {
            if (strs[0] == "") return "";
            char c = strs[0][t];
            for (int i = 1; i < n; ++i) {
                if (strs[i][t] != c) {
                   check = false;
                   break;
                }
            }
            if (!check) break;
            else {
                r = r + c;
                ++t;
            }
        }
        return r;
    }
};
