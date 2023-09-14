/*
copy all nums from vector to a set to create a lookup table
for each number in the set check if num - 1 exists in the set
if yes, that means this one may be a 'part' of a sequence (and not the start)
hence we skip this
if num - 1 does not exist in the set, it means that a sequence starts from this number
then we see if num + 1, num + 2, ... exists in the sequence, if yes, we increment a counter
we stop when some num + x is not present in the sequence
we update longest if this is longer than the previously seen longest sequence's length
*/
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


/*
create a range boolean vector from the smallest to the largest element
where the smallest will be at index 0 and the largest will be at index largest - smallest
all the numbers that exist between this range can be set to true in the vector
A single pass to see the longest consecutive sequence of trues
Gives TLE
*/
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