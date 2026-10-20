class Solution {
public:
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int m = pattern.size();
        int len = 0;

        lps[0] = 0;

        int i = 1;
        while(i < m) {
            if(pattern[i] == pattern[len]) {
                len++;
                lps[i++] = len;
            }
            else {
                if(len != 0) {
                    len = lps[len - 1]; // Try a shorter prefix
                }
                else {
                    lps[i++] = 0; // No matching prefix
                }
            }
        }
    }

    bool KMPSearch(vector<int>& pat, vector<int>& txt) {
        int n = txt.size();
        int m = pat.size();

        vector<int> lps(m, 0);
        computeLPS(pat, lps); // Build LPS array for the pattern

        int i = 0, j = 0;
        while(i < n) {
            if(txt[i] == pat[j]) {
                i++; j++;
            }

            if(j == m) {
                return true; // Entire pattern found
            }

            else if(i < n && txt[i] != pat[j]) {
                if(j != 0) {
                    j = lps[j - 1]; // Avoid rechecking matched elements
                }
                else {
                    i++;
                }
            }
        }

        return false;
    }

    bool isRotationPossible(vector<int>& vec1, vector<int>& vec2) {
        vector<int> temp = vec2;
        temp.insert(temp.end(), vec2.begin(), vec2.end()); // vec2 + vec2 contains all rotations

        return KMPSearch(vec1, temp); // Check if vec1 occurs in temp
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int result = 0;

        for(int k = 1; k <= n; k++) {
            if(n % k != 0) continue; // Only consider divisors of n

            bool valid = true;

            for(int st = 0; st < n; st += k) {
                // Compare corresponding blocks of size k
                vector<int> vec1(nums.begin() + st, nums.begin() + st + k);
                vector<int> vec2(sorted.begin() + st, sorted.begin() + st + k);

                if(!isRotationPossible(vec1, vec2)) {
                    valid = false;
                    break;
                }
            }

            if(valid) result += k; // Add k if every block is a valid rotation
        }

        return result;
    }
};