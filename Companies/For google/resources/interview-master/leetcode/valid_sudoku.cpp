class Solution {
public:
    int geti(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        else return 10;
    }
    bool checkl(vector<vector<char>> &board, int length, int width) {       
        vector<int> table;
        for (int l = 0; l < length; ++l) {
            table = vector<int>(10, 0);
            for (int w = 0; w < width; ++w) {
                if (board[l][w] != '.' ) {
                    if (table[geti(board[l][w])]) return false;
                    table[geti(board[l][w])] = 1;
                }
            }
        }
        return true;
    }
    
    bool checkw(vector<vector<char>> &board, int length, int width) {       
        vector<int> table;
        for (int w = 0; w < width; ++w) {
            table = vector<int>(10, 0);
            for (int l = 0; l < length; ++l) {
                if (board[l][w] != '.' ) {
                    if (table[geti(board[l][w])]) return false;
                    table[geti(board[l][w])] = 1;
                }
            }
        }
        return true;
    }
    
    bool check3(vector<vector<char>> &board, int length, int width) {
        vector<int> table;
        for (int l = 0; l < length; l += 3) {
            for (int w = 0; w < width; w += 3) {
            table = vector<int>(10, 0);
            for (int i = l; i < l + 3; ++i) {
                    for (int j = w; j < w + 3; ++j) {
                        if (board[i][j] != '.' ) {
                            if (table[geti(board[i][j])]) return false;
                            table[geti(board[i][j])] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = board.size();
        int width = board[0].size();
        return checkl(board, length, width) && checkw(board, length, width) && check3(board, length, width);
    }
};
