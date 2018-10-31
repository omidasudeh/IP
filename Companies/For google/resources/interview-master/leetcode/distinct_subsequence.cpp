class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ls = S.length(), lt = T.length();
        vector<vector<int>> f(lt + 1, vector<int>(ls + 1, 0));
        for (int i = 0; i <= ls; ++i) f[0][i] = 1;
        for (int i = 1; i <= lt; ++i) {
            for (int j = 1; j <= ls; ++j) {
                f[i][j] = f[i][j - 1];
                if (S[j - 1] == T[i - 1]) f[i][j] += f[i - 1][j - 1];
            }
        }
        return f[lt][ls];
    }
};
