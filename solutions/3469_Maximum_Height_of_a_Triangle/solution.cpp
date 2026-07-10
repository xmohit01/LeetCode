class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        int odd_red = sqrt(red);
        int even_red = (sqrt(4*red + 1) - 1) / 2;
        int odd_blue = sqrt(blue);
        int even_blue = (sqrt(4*blue + 1) - 1) / 2;

        int ans1, ans2;

        if(odd_red > even_blue) ans1 = 2 * even_blue + 1;
        else ans1 = 2 * odd_red;
        
        if(odd_blue > even_red) ans2 = 2 * even_red + 1;
        else ans2 = 2 * odd_blue;

        return max(ans1, ans2);
    }
};