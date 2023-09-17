/*
for each height, we calculate the maximum area it can be in
for example:
         ___
|       |   |
|    ___|   |
|   |   | 3 |
|   | 2 |   |
|___|___|___|____

in the above histogram, first for height = 2, we find the largest width that can contain 2 (i.e, width = 2)
then we do the same for 3 (width = 1)

now although just 2 will have an area of 2x1, we don't really need to consider it as we are only concerned with max area and max area that can contain height = 2 is 2x2.

basically, we can consider all possible areas as in bruteforce, but we don't need to because we can find the widest a given height can stretch and that will be the max area for that height. we do this for all heights and take the maxarea overall.

to implement this we have 2 arrays: leftsmall and rightsmall
for all i, leftsmall[i] is the height smaller than heights[i] to the left. so basically it is the first height to the left of heights[i] that canNOT contain heights[i], i.e, it is the left limit for the largest width of heights[i]
similarly, rightsmall[i] is the height smaller than heights[i] to the right, i.e., the right limit for the largest width of heights[i]

thus, once we populate leftsmall and rightsmall for all i,
we can simply calculate maxarea[i] as (rightsmall[i] - leftsmall[i]) * height[i] (with index adjustments)

and the final output is max of maxarea

this is O(n) time and O(n) space with 3 passes
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        stack<int> smaller;
        vector<int> leftsmall(heights.size(), 0), rightsmall(heights.size(), heights.size() - 1);
        
        // populate leftsmall
        for (int i = 0; i < heights.size(); ++i) {
            while (!smaller.empty() && heights[smaller.top()] >= heights[i]) {
                smaller.pop();
            }
            
            if (!smaller.empty()) leftsmall[i] = smaller.top() + 1;
            
            smaller.push(i);
        }
                
        smaller = stack<int>();
        
        // populate rightsmall
        for (int i = heights.size() - 1; i >= 0; --i) {
            while (!smaller.empty() && heights[smaller.top()] >= heights[i]) {
                smaller.pop();
            }
            
            if (!smaller.empty()) rightsmall[i] = smaller.top() - 1;

            smaller.push(i);
        }
                
        // get maxarea
        for (int i = 0; i < heights.size(); ++i) {
            maxarea = max(maxarea, (rightsmall[i] - leftsmall[i] + 1) * heights[i]);
        }
        
        return maxarea;
    }
};

// for all i, for all j
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int maxarea = 0;
//         for (int i = 0; i < heights.size(); ++i) {
//             int minheight = INT_MAX;
//             for (int j = i; j < heights.size(); ++j) {
//                 minheight = min(minheight, heights[j]);
//                 maxarea = max(maxarea, (j - i + 1) * minheight);
//             }
//         }
        
//         return maxarea;
//     }
// };