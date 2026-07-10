class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int freq = 0;
        for(int i = 0; i < k; i++){
            if(blocks[i] == 'B') freq++;
        }

        int temp = freq;
        for(int i = k; i < blocks.size(); i++){
            if(blocks[i - k] == 'B') temp--;
            if(blocks[i] == 'B') temp++;

            freq = max(freq, temp);
        }

        return k - freq;
    }
};