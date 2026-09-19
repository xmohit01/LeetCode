class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {

        int closestX;
        if(xCenter > x2) closestX = x2;
        else if(xCenter < x1) closestX = x1;
        else closestX = xCenter;

        int closestY;
        if(yCenter > y2) closestY = y2;
        else if(yCenter < y1) closestY = y1;
        else closestY = yCenter;

        return sqrt(((xCenter - closestX) * (xCenter - closestX)) + ((yCenter - closestY) * (yCenter - closestY))) <= radius;
    }
};