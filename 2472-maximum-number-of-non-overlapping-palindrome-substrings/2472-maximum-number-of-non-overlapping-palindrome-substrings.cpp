class Solution {
public:
    bool isPalindrome(string& s){
        int st = 0, end = s.length() - 1;
        while(st < end){
            if(s[st++] != s[end--]) return false;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int len = s.length();
        if(k == 1) return len;

        vector<int> dp(len + 1, 0);

        for(int i = 1; i <= len; i++){

            dp[i] = dp[i - 1];

            string temp = "";

            for(int j = i - 1; j >= 0; j--){

                temp += s[j];

                if(temp.length() >= k && isPalindrome(temp)){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[len];
    }
};