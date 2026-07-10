class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();

        int count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++){
            if(tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u'){
                if(i < (n / 2)) count1++;
                else count2++;
            }
        }

        return count1 == count2;
    }
};