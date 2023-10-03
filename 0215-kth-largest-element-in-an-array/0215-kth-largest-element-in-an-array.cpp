/*
use min-heap
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (auto& num : nums) {
            klargest.push(num);
            
            if (klargest.size() == k + 1) klargest.pop();
        }
        
        return klargest.top();
    }
    
private:
    priority_queue<int, vector<int>, greater<int>> klargest;
};