/*
create a frequency table of nums
insert (frequency, number) in a max heap, ordered by frequency
pop top k elements
Complexity will be O(klogn)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) {
            ++freq[num];
        }
        
        priority_queue<pair<int, int>> heapq;
        for (auto it : freq) {
            heapq.push(make_pair(it.second, it.first));
        }
        
        vector<int> topk;
        for (int i = 0; i < k; ++i) {
            topk.push_back(heapq.top().second);
            heapq.pop();
        }
        
        return topk;
    }
};