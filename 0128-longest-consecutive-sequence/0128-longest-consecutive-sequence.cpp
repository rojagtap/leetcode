class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> lookup(nums.begin(), nums.end());
        
        int longest = 0;
        for(auto num: lookup){
            if(lookup.find(num - 1) == lookup.end()) {
                int length = 1; 
                while(lookup.find(num + length) != lookup.end()) {
                    ++length;
                }

                longest = max(longest, length);
            } 

        }
        return longest;
    }
};


// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if (nums.empty()) return 0;
        
//         int smallest = *min_element(nums.begin(), nums.end());
//         int largest = *max_element(nums.begin(), nums.end());
        
//         vector<bool> range(largest - smallest + 1, false);
//         for (int i = 0; i < nums.size(); ++i) {
//             range[nums[i] - smallest] = true;
//         }
        
//         int longest = 0, count = 0;
//         for (auto flag : range) {
//             if (!flag && count) {
//                 longest = max(longest, count);
//                 count = 0;
//             } else if (flag) {
//                 ++count;
//             }
//         }
        
//         return max(longest, count);
//     }
// };