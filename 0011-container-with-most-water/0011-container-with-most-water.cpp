/*
Take a left index and a right index. This is the widest area.
If we wish to increase the area, we need a increase in height.
So we come closer for lower heights, i.e., 
if left is smaller, move left forward
if right is smaller, move right backward
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        
        int maxArea = 0;
        while (l < r) {
            maxArea = max(maxArea, (r - l) * (min(height[l], height[r])));
            
            if (height[l] <= height[r]) ++l;
            else --r;
        }
        
        return maxArea;
    }
};