class Solution {
public:

    void helper(vector<vector<char>>& board, int row, int col){
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return;
        if(board[row][col] != 'O') return;

        board[row][col] = 'S'; // safe krdo 
        helper(board, row - 1, col);
        helper(board, row + 1, col);
        helper(board, row, col - 1);
        helper(board, row, col + 1);
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O') helper(board, i, 0);
            if(board[i][m - 1] == 'O') helper(board, i, m - 1);
        }

        for(int i = 0; i < m; i++){
            if(board[0][i] == 'O') helper(board, 0, i);
            if(board[n - 1][i] == 'O') helper(board, n - 1, i);
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j] == 'S') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};