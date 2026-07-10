class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][101][101][4];
    
    long long helper(const string& word1, const string& word2, const string& target, int t_idx, int idx1, int idx2, int mask){
        
        if (t_idx == target.length()){
            return (mask == 3) ? 1 : 0; 
        }

        if (dp[t_idx][idx1][idx2][mask] != -1){
            return dp[t_idx][idx1][idx2][mask];
        }

        long long ways = 0;

        for (int i = idx1; i < word1.length(); i++) {
            if (word1[i] == target[t_idx]){
                ways = (ways + helper(word1, word2, target, t_idx + 1, i + 1, idx2, mask | 1)) % mod;
            }
        }
        
        for (int j = idx2; j < word2.length(); j++){
            if (word2[j] == target[t_idx]){
                ways = (ways + helper(word1, word2, target, t_idx + 1, idx1, j + 1, mask | 2)) % mod;
            }
        }

        return dp[t_idx][idx1][idx2][mask] = ways;
    }
    
    int interleaveCharacters(string word1, string word2, string target){
        
        memset(dp, -1, sizeof(dp));
        
        return helper(word1, word2, target, 0, 0, 0, 0);
    }
};