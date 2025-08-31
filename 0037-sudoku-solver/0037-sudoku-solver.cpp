class Solution {
public:
    bool valid(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; ++i) {
            if (board[r][i] == ch || board[i][c] == ch) return false;
        }
        int gr = r/3 * 3, gc = c/3 * 3;
        for (int i = gr; i < gr+3; ++i) {
            for (int j = gc; j < gc+3; ++j) {
                if (board[i][j] == ch) return false;
            }
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board) {
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    for (char ch = '1'; ch <= '9'; ++ch) {
                        if (valid(board, r, c, ch)) {
                            board[r][c] = ch;
                            if (backtrack(board)) return true;
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};