#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<vector<char> > &board, string word, int i, int m, int j, int n, vector<vector<bool> > &used) {
        if (word.length() == 0) return true;
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
		if (used[i][j]) return false;
        if (board[i][j] == word[0]) {
            used[i][j] = true;
            string next = word.substr(1);
            if (search(board, next, i + 1, m, j, n, used) || search(board, next, i, m, j + 1, n, used)
                || search(board, next, i - 1, m, j, n, used) || search(board, next, i, m, j - 1, n, used))
                return true;
            used[i][j] = false;
        }
		return false;
    }
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = board.size();
        if (m == 0) return false;
        int n = board[0].size();
        vector<vector<bool> > used(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (search(board, word, i, m, 0, j, used)) return true;
			}
		}
		return false;
    }
};

int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    Solution s;
    vector<vector<char> > board;
	vector<char> first; first.push_back('a'), first.push_back('b');
	vector<char> second; second.push_back('c'), second.push_back('d');
	board.push_back(first), board.push_back(second);
    string word = "abcd";
    cout << s.exist(board, word) << endl;
    return 0;
}