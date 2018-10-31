class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ls = S.length(), lt = T.length();
        string ans = "";
        int l = 0, r = 0, find = 0;
        vector<int> count(256);
        for (int i = 0; i < lt; ++i) {
            count[T[i]]++;
        }
        while (r < ls) {
            while (r < ls && find < lt) {
                count[S[r]]--;
                if (count[S[r]] >= 0) find++;
                ++r;
            }
            if (find < lt) break;
            while (l < r) {
                count[S[l]]++;
                if (count[S[l]] > 0) break;
                ++l;
            }
            if (ans == "" || r - l < ans.size()) {
                ans = S.substr(l, r - l);
            }
            ++l;
            --find;
        }
        return ans;
    }
};
