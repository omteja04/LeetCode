class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == ch)
                return 0;
            if (board[row][i] == ch)
                return 0;
            if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch)
                return 0;
        }
        return true;
    }
    bool rec(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isValid(board, i, j, ch)) {
                            board[i][j] = ch;
                            if (rec(board))
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    return 0;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) { rec(board); }
};