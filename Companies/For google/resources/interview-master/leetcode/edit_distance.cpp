#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l1 = word1.length(), l2 = word2.length();
        vector<vector<int> > edit(l1 + 1, vector<int>(l2 + 1, 0));
        for (int j = 1; j <= l2; ++j) edit[0][j] = j;
        for (int i = 1; i <= l1; ++i) edit[i][0] = i;
        for (int i = 1; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                edit[i][j] = min(edit[i - 1][j] + 1, edit[i][j - 1] + 1);
                if (word1[i - 1] != word2[j - 1]) edit[i][j] = min(edit[i][j], edit[i - 1][j - 1] + 1);
                else edit[i][j] = min(edit[i][j], edit[i - 1][j - 1]);
            }
        }
        return edit[l1][l2];
    }
};

int main() {
	Solution s;
	string word1 = "a", word2 = "b";
	cout << s.minDistance(word1, word2) << endl;
	return 0;
}