class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int num = 0;
        int ans = 0;
        int l = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') num++;
            else {
                num--;
                if (num == 0) 
                    if (i - l + 1 > ans) ans = i - l + 1;
                if (num < 0) l = i + 1, num = 0;
            }
        }
        l = n - 1, num = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == ')') num++;
            else {
                num--;
                if (num == 0) 
                    if (l - i + 1 > ans) ans = l - i + 1;
                if (num < 0) num = 0, l = i - 1;
            }
        }
        return ans;
    }
};
