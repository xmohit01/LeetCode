class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++){
            unordered_map<int, int> m;

            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;
                if(m[board[i][j]] == 0){
                    m[board[i][j]] = 1;
                }
                else return false;
            }
        }
        for(int i = 0; i < 9; i++){
            unordered_map<int, int> m;
            
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(m[board[j][i]] == 0){
                    m[board[j][i]] = 1;
                }
                else return false;
            }
        }

        for(int i = 0; i < 9; i += 3){
            for(int j = 0; j < 9; j += 3){
                unordered_map<int, int> m;

                for(int idx1 = i; idx1 < i + 3; idx1++){
                    for(int idx2 = j; idx2 < j + 3; idx2++){
                        if(board[idx1][idx2] == '.') continue;
                        if(board[idx1][idx2] != '.' && m[board[idx1][idx2]] == 0){
                            m[board[idx1][idx2]] = 1;
                        }
                        else return false;
                    }
                }
            }
        }

        return true;
    }
};