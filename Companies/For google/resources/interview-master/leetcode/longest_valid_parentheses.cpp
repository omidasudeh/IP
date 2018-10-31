class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> valid(n, 0);
        int longest = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] == ')') {
                if (s[i - valid[i - 1] - 1] == '(') {
                    valid[i] = 2 + valid[i - 1];
                    if (i - valid[i - 1] - 2 >= 0) valid[i] += valid[i - valid[i - 1] - 2];
                }
                else valid[i] = 0;
            }
            else {
                valid[i] = 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (valid[i] > longest) longest = valid[i];
        }
        return longest;
    }
};
