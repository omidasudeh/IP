class Solution {
public:
    bool match(char a, char b) {
        if (a == b || b == '?' || b == '*') return true;
        return false;
    }
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ss = strlen(s), sp = strlen(p);
        vector<vector<bool>> table(2, vector<bool>(sp + 1, false));
        table[0][0] = true;
        for (int i = 0; i <= ss; ++i) {
            for (int j = 0; j <= sp; ++j) {
                if (i == 0 && j == 0) continue;
                table[i % 2][j] = false;
                if (i > 0 && j > 0) {
                    if (match(s[i - 1], p[j - 1]) && table[(i - 1) % 2][j - 1])
                        table[i % 2][j] = true;
                }
                if (j == 1) {
                    if (p[j - 1] == '*')
                        table[i % 2][j] = true;
                }
                if (i > 0 && j > 1) {
                    if (p[j - 1] == '*' && table[(i - 1) % 2][j])
                        table[i % 2][j] = true;
                }
                if (j > 1) {
                    if (p[j - 1] == '*' && table[i % 2][j - 1])
                        table[i % 2][j] = true;
                }
            }
        }
        return table[ss % 2][sp];
    }
};
