class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == dig) return false;
            if (board[i][col] == dig) return false;
        }

        int strow = (row / 3) * 3;
        int stcol = (col / 3) * 3;

        for (int i = strow; i < strow + 3; i++) {
            for (int j = stcol; j < stcol + 3; j++) {
                if (board[i][j] == dig) return false;
            }
        }

        return true;
    }

    bool helper(vector<vector<char>>& board) {

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {

                if (board[row][col] == '.') {

                    for (char dig = '1'; dig <= '9'; dig++) {

                        if (isSafe(board, row, col, dig)) {

                            board[row][col] = dig;

                            if (helper(board))
                                return true;

                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};