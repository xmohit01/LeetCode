class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();

        vector<int> records;
        for(int i = 0; i < n; i++){
            int k = records.size();
            if(operations[i] == "+") records.push_back(records[k - 1] + records[k - 2]);

            else if(operations[i] == "D") records.push_back(2 * records[k - 1]);

            else if(operations[i] == "C") records.pop_back();

            else records.push_back(stoi(operations[i]));
        }

        int ans = 0;
        for(int i : records) ans += i;

        return ans;
    }
};