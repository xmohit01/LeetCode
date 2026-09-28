class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;

        sort(products.begin(), products.end());

        string checker = "";
        int len = 0;
        for(char c : searchWord) {
            checker += c;
            len++;

            vector<string> tempResult;

            for(string& check : products) {
                if(check.substr(0, len) == checker) tempResult.push_back(check);

                if(tempResult.size() == 3) break;
            }

            result.push_back(tempResult);
        }

        return result;
    }
};