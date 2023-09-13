/*
create a count table of all elements in nums
reverse the count table by creating a vector<vector<int>> of size equal to nums.size()
the size of count table will never exceed nums.size()
for each count, append the element of nums having that count to the inner vector
traverse the reverse vector from the back (since we want top k) and fill a result vector
until size is >= k
return the first k elements
complexity will be O(n)
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) {
            ++freq[num];
        }
        
        vector<vector<int>> reverse(nums.size() + 1);
        for (auto it : freq) {
            reverse[it.second].push_back(it.first);
        }
        
        vector<int> topk;
        int i = nums.size();
        while (i >= 0 && topk.size() < k) {
            topk.insert(topk.end(), reverse[i].begin(), reverse[i].end());
            --i;
        }
        
        return topk;
    }
};

// /*
// create a frequency table of nums
// insert (frequency, number) in a max heap, ordered by frequency
// pop top k elements
// complexity will be O(klogn)
// */
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int, int> freq;
//         for (auto num : nums) {
//             ++freq[num];
//         }
        
//         priority_queue<pair<int, int>> heapq;
//         for (auto it : freq) {
//             heapq.push(make_pair(it.second, it.first));
//         }
        
//         vector<int> topk;
//         for (int i = 0; i < k; ++i) {
//             topk.push_back(heapq.top().second);
//             heapq.pop();
//         }
        
//         return topk;
//     }
// };