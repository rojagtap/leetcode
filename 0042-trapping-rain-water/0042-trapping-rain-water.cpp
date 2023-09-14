/*
for any given spot, the amount of water accumulated will be
min(heighest elevation to the left, heighest elevation to the right) - elevation of the spot

one way to apprach this is have 2 arrays
one that maintains the heighest to the left for each spot-- maxLeft
and another that maintains the heighest to the right for each spot-- maxRight
finally, traverse for each spot i, and compute the water accumulated as:
min(maxLeft[i], maxRight[i]) - height[i]

this approach is O(n) in time but O(n) in space
we can try to do this in constant space

now since we fill the maxLeft array from left and maxRight from right
we can have two iterators-- left and right, maxLeft and maxRight for tracking maxes respectively
now let's say we are at position 3 in example 1
i.e., left is at 3 and right is at 8
at this position, the maxLeft is 2 and maxRight is 2
but in reality, the "true" maxRight for position 3 is 3 (from observation)
however, we are not concerned with the high values of right at the moment
meaning even if we somehow move right iterator to position 6
and get the "true" maxRight which is 3,
it wouldn't matter as we want the MIN of both
and maxLeft is definitely the "true" maxLeft for poisition 3
so we can safely say that we can take just maxLeft as it is the min
now say at some point, if maxLeft is greater than maxRight, then we switch to right
i.e., now we add the water from right with the same logic
we are not concerned with the "true" maxLeft for say, position 8 as long as "maxRight" is the "true" maxRight for position 8
and maxRight is less than the current maxLeft.
see https://www.youtube.com/watch?v=ZI2z5pq0TqA
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = height[left], maxRight = height[right];
        
        int water = 0;
        while (left < right) {
            if (maxLeft <= maxRight) {
                ++left;
                maxLeft = max(maxLeft, height[left]);
                water += maxLeft - height[left];
            } else {
                --right;
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
            }
        }
        
        return water;
    }
};