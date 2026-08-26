class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int count = 0;
        int idx = 0;
        for(idx; idx < n; idx++){
            if(s[idx] == '1') count++;

            if(count == k) break;
        }
        if(count < k) return "";

        int left = 0;
        while(s[left] == '0') left++;

        string ans = s.substr(left, idx - left + 1);
        
        for(int right = idx + 1; right < n; right++){
            if(s[right] == '1') count++;
            
            while(count > k){
                if(s[left] == '1') count--;

                left++;
            }

            while(left <= right && s[left] == '0') left++;

            string curr = s.substr(left, right - left + 1);

            if(curr.length() < ans.length() || (curr.length() == ans.length() && curr < ans)){
                ans = curr;
            }
        }

        return ans;
    }
};