//Sourround regions
class Solution {
public:

    vector<vector<char>> cboard;
    int r, c;
    
    void ffill(const vector<vector<char>> &board, int i, int j) {
        cboard[i + 1][j + 1] = 'O';
        if (j < c - 1 && board[i][j + 1] == 'O' && cboard[i + 1][j + 2] == 'X') ffill(board, i, j + 1);
        if (j > 0 && board[i][j - 1] == 'O' && cboard[i + 1][j] == 'X') ffill(board, i, j - 1);
        if (i > 0 && board[i - 1][j] == 'O' && cboard[i][j + 1] == 'X') ffill(board, i - 1, j);
        if (i < r - 1 && board[i + 1][j] == 'O' && cboard[i + 2][j + 1] == 'X') ffill(board, i + 1, j);
    }

    void solve(vector<vector<char>> &board) {
        r = board.size();
        if (r != 0) {
            c = board[0].size();
            cboard = vector<vector<char>>(r + 2, vector<char>(c + 2));
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    cboard[i+1][j+1] = 'X';
                }
            }
            int i = 1;
            for (int j = 1; j <= c; ++j) {
                if (board[i - 1][j - 1] == 'O') {
                    ffill(board, i - 1, j - 1);
                }
            }
            i = r;
            for (int j = 1; j <= c; ++j) {
                if (board[i - 1][j - 1] == 'O') ffill(board, i - 1, j - 1);
            }
            int j = 1;
            for (int s = 2; s < r; ++s) {
                if (board[s - 1][j - 1] == 'O') ffill(board, s - 1, j - 1);
            }
            j = c;
            for (int s = 2; s < r; ++s) {
                if (board[s - 1][j - 1] == 'O') ffill(board, s - 1, j - 1);
            }
            for (int i = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                    board[i][j] = cboard[i+1][j+1];
                }
            }
        }
    }
};

