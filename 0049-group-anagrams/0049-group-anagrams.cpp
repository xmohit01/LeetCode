class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        if(n == 1) return {strs};
        vector<string> sorted(n);
        
        for(int i = 0; i < n; i++){
            sorted[i] = strs[i];
            sort(sorted[i].begin(), sorted[i].end());
        }

        vector<vector<string>> ans;
        vector<int> visited(n,-1);
        vector<int> ary;
        for(int i = 0; i < n; i++){
            
            
            vector<string> a;
            for(int j = i; j < n; j++){
                if(sorted[i] == sorted[j] && visited[j]==-1){

                        visited[j]=1;

                        a.push_back(strs[j]);
                    }
                }
                if(!a.empty()) ans.push_back(a);
            }
           
        return ans;
    }
};