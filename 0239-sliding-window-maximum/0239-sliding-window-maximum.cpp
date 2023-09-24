/*
sliding window

the first thought when thinking about O(n) solution is:
have a window of size k and keep a maxelement int
if new element arriving in sliding is > maxelement, update max

the problem with this approach comes when the element leaving the window is maxelement and the new element coming in is not.
Here we would like to have the second best element in the window to replace the maxelement when it leaves

the solution to this is to maintain the elements in the list in decreasing order as we iterate it and remove elements from the start as we slide the window
basically we are keeping the max, second-max, .... elements (in that order) so that when we remove max, the second-max is there, and so on
to implement this, we want a deque as we want to insert and delete elements from both sides

for each element arriving, we want to pop out all the values to the left (in the deque) that are smaller than the element. this way we can achieve a decreasing value deque
(or monotonic deque)
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxes;
        deque<int> monotonic;
        
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            while (!monotonic.empty() && nums[monotonic.back()] < nums[r]) {
                monotonic.pop_back();
            }
            monotonic.push_back(r);
            
            if (r - l + 1 == k) {
                maxes.push_back(nums[monotonic.front()]);

                if (monotonic.front() == l) {
                    monotonic.pop_front();
                }
                
                ++l;
            }
        }
        
        return maxes;
    }
};