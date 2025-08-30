class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bitset<9> rows[9], cols[9], boxes[9];
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                int num = board[i][j] - '1';
                if (rows[i][num]) return false;
                rows[i][num] = 1;
                if (cols[j][num]) return false;
                cols[j][num] = 1;
                int box = (i/3)*3 + j/3;
                if (boxes[box][num]) return false;
                boxes[box][num] = 1;
            }
        }
        return true;
    }
};