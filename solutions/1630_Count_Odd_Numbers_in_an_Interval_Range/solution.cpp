class Solution {
public:
    int countOdds(int low, int high) {
        // if(low % 2 == 0){
        //     if(high % 2 == 0) return (high - low) / 2;

        //     else return ((high - low) / 2) + 1;
        // }
        // else{
        //     if(high % 2 == 0) return ((high - low) / 2) + 1;

        //     else return ((high - low) / 2) + 1;
        // }

        return ((high - low) / 2) + ((low % 2) || (high % 2));
    }
};