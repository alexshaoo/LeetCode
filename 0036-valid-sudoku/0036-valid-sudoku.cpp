class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            int seen[9] = {0};
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    if (seen[board[i][j] - '1']) return false;
                    seen[board[i][j] - '1'] = 1;
                }
            }
        }
        for (int i = 0; i < 9; ++i) {
            int seen[9] = {0};
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.') {
                    if (seen[board[j][i] - '1']) return false;
                    seen[board[j][i] - '1'] = 1;
                }
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                int seen[9] = {0};
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (board[i+x][j+y] != '.') {
                            if (seen[board[i+x][j+y] - '1']) return false;
                            seen[board[i+x][j+y] - '1'] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};