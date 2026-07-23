class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int row, int col, int idx){
        if(idx == word.size()) return true;
        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[idx]) return false;

        board[row][col] = '$';
        bool leftCheck = helper(board, word, row - 1, col, idx + 1);
        bool rightCheck = helper(board, word, row + 1, col, idx + 1);
        bool topCheck = helper(board, word, row, col - 1, idx + 1);
        bool downCheck = helper(board, word, row, col + 1, idx + 1);
        board[row][col] = word[idx];

        return leftCheck || rightCheck || topCheck || downCheck;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(helper(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
};