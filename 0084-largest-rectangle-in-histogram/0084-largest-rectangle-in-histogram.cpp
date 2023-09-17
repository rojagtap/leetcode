/*
Approach 3: Optimal

in the previous approach, we calculated the left and right small for each heights[i]
and then simply calculated the area as (right - left) * height

for this we needed 3 passes on heights[i]:
one for populating leftsmall
one for populating rightsmall
one for computing the maxarea

however, we can solve this using just 1 pass and without using 2 separate arrays for left and right small

in the leftsmall pass
we push heights[i] to the stack every time heights[i] > stack.top()
whereas we pop when heights[i] <= stack.top()

so here, whenever, heights[i] < stack.top(), then heights[i] will be the rightsmall of stack.top() because it was the first element we saw that was smaller than the top
also, stack[-2] will be the leftsmall for stack.top() as we pushed stack.top() because it was > stack[-2].

in this way we can calculate the area for each element, only this time our centre isn't heights[i], but stack.top() with a condition

this is again, O(n) and O(n), but is done in 1 pass
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxarea = 0;
        stack<int> smaller;
        
        for (int i = 0; i < heights.size(); ++i) {
            while (!smaller.empty() && heights[smaller.top()] > heights[i]) {
                int height = heights[smaller.top()];
                smaller.pop();
                
                int leftsmall = 0;
                if (!smaller.empty()) leftsmall = smaller.top() + 1;
                int width = i - leftsmall;
                
                maxarea = max(maxarea, width * height);
            }
            
            smaller.push(i);
        }
        
        while (!smaller.empty()) {
            int height = heights[smaller.top()];
            smaller.pop();
            
            int leftsmall = 0;
            if (!smaller.empty()) leftsmall = smaller.top() + 1;
            int width = heights.size() - leftsmall;
            
            maxarea = max(maxarea, width * height);
        }
        
        return maxarea;
    }
};

// /*
// Approach 2: Sub-Optimal
// for each height, we calculate the maximum area it can be in
// for example:
//          ___
// |       |   |
// |    ___|   |
// |   |   | 3 |
// |   | 2 |   |
// |___|___|___|____

// in the above histogram, first for height = 2, we find the largest width that can contain 2 (i.e, width = 2)
// then we do the same for 3 (width = 1)

// now although just 2 will have an area of 2x1, we don't really need to consider it as we are only concerned with max area and max area that can contain height = 2 is 2x2.

// basically, we can consider all possible areas as in bruteforce, but we don't need to because we can find the widest a given height can stretch and that will be the max area for that height. we do this for all heights and take the maxarea overall.

// to implement this we have 2 arrays: leftsmall and rightsmall
// for all i, leftsmall[i] is the height smaller than heights[i] to the left. so basically it is the first height to the left of heights[i] that canNOT contain heights[i], i.e, it is the left limit for the largest width of heights[i]
// similarly, rightsmall[i] is the height smaller than heights[i] to the right, i.e., the right limit for the largest width of heights[i]

// thus, once we populate leftsmall and rightsmall for all i,
// we can simply calculate maxarea[i] as (rightsmall[i] - leftsmall[i]) * height[i] (with index adjustments)

// and the final output is max of maxarea

// this is O(n) time and O(n) space with 3 passes
// */
// class Solution {
// public:
//     int largestRectangleArea(vector<int>& heights) {
//         int maxarea = 0;
//         stack<int> smaller;
//         vector<int> leftsmall(heights.size(), 0), rightsmall(heights.size(), heights.size() - 1);
        
//         // populate leftsmall
//         for (int i = 0; i < heights.size(); ++i) {
//             while (!smaller.empty() && heights[smaller.top()] >= heights[i]) {
//                 smaller.pop();
//             }
            
//             if (!smaller.empty()) leftsmall[i] = smaller.top() + 1;
            
//             smaller.push(i);
//         }
                
//         smaller = stack<int>();
        
//         // populate rightsmall
//         for (int i = heights.size() - 1; i >= 0; --i) {
//             while (!smaller.empty() && heights[smaller.top()] >= heights[i]) {
//                 smaller.pop();
//             }
            
//             if (!smaller.empty()) rightsmall[i] = smaller.top() - 1;

//             smaller.push(i);
//         }
                
//         // get maxarea
//         for (int i = 0; i < heights.size(); ++i) {
//             maxarea = max(maxarea, (rightsmall[i] - leftsmall[i] + 1) * heights[i]);
//         }
        
//         return maxarea;
//     }
// };


// /*
// Approach 1: Brute Force
// for all i, for all j
// */
// // class Solution {
// // public:
// //     int largestRectangleArea(vector<int>& heights) {
// //         int maxarea = 0;
// //         for (int i = 0; i < heights.size(); ++i) {
// //             int minheight = INT_MAX;
// //             for (int j = i; j < heights.size(); ++j) {
// //                 minheight = min(minheight, heights[j]);
// //                 maxarea = max(maxarea, (j - i + 1) * minheight);
// //             }
// //         }
        
// //         return maxarea;
// //     }
// // };