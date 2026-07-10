class Solution {
public:

    static bool reff(pair<char, int>& a, pair<char, int>& b){
        return a.second > b.second;
    }

    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> m;
        for(int i = 0; i < n; i++) m[s[i]]++;

        vector<pair<char, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), reff);

        int k = 0;
        for(auto pair : v){
            while(pair.second--) s[k++] = pair.first;
        }

        return s;
    }
};