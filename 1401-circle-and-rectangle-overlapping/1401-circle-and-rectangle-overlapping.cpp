class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int closestX = (xCenter > x2) ? x2 : (xCenter < x1) ? x1 : xCenter;

        int closestY = (yCenter > y2) ? y2 : (yCenter < y1) ? y1 : yCenter;

        return sqrt(((xCenter - closestX) * (xCenter - closestX)) + ((yCenter - closestY) * (yCenter - closestY))) <= radius;
    }
};