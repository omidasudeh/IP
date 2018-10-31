// DP algorithm in O(n2)
class Solution {
public:
    string longestPalindrome(string s) {
        int n =  s.length();
        int table[1000][1000];
        memset(table, 0, sizeof(table));
        for (int i = 0; i < n; ++i) {
            table[i][i] = 1;
        }
        int len, start = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                table[i][i + 1] = 1;
                len = 2;
                start = i;
            }
        }
        for (int l = 3; l <= n; ++l) {
            for (int i = 0; i < n - l + 1; ++i) {
                if (s[i] == s[i + l - 1] && table[i + 1][i + l - 2]) {
                    table[i][i + l - 1] = 1;
                    len = l;
                    start = i;
                }
            }
        }
        return s.substr(start, len);
    }
};
