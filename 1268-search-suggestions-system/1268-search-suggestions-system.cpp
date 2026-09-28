class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;

        sort(products.begin(), products.end());

        string prefix = "";

        for(char c : searchWord) {
            prefix += c;

            vector<string> temp;

            auto it = lower_bound(products.begin(), products.end(), prefix);

            for(int i = 0; i < 3 && (it + i) != products.end(); i++) {
                if((it + i)->compare(0, prefix.size(), prefix) != 0) break;

                temp.push_back(*(it + i));
            } 

            result.push_back(temp);
        }

        return result;
    }
};