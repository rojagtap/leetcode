/*
note that all max jump values are positive, i.e., jumps will always go forward
so from 0 we can go to end of nums as long as some end - x can reach to end
the criteria for reaching is
all end - x > 0 or if some end - x == 0 then there must be some end - x - y such that it directly goes to end - i such that end - i is end or reaches end

why cant we directly check for 0 in nums and return false if found?
this test case: [2, 0, 0]

why cant we check for all values from 0 - n such that before arriving a 0, i + nums[i] should reach n?
this test case: [3, 0, 0, 1, 4]
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;
    }
};

// /*
// bruteforce
// start from 0 (as given) and recursively try all i + x where x ranges from 1 to nums[i]
// use a cache for recording each index. mark as false if all jump values are tried from that index and dont lead to size - 1
// if size - 1 is found, just return true
// the cache also indicates a visited index so do not jump to that index (this also prevents infinite loops)
// */
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//         dp = vector<int>(nums.size(), -1);
//         return recurse(nums, 0);
//     }

// private:
//     vector<int> dp;
//     bool recurse(vector<int>& nums, int idx) {        
//         if (dp[idx] != -1) {
//             return dp[idx];
//         }

//         if (idx == nums.size() - 1) {
//             return true;
//         }

//         if (nums[idx] == 0) {
//             return dp[idx] = false;
//         }

//         for (int i = 1; i <= nums[idx]; ++i) {
//             if (idx + i < nums.size() && dp[idx + i] == -1 && recurse(nums, idx + i)) {
//                 return dp[idx] = true;
//             }
//         }

//         return dp[idx] = false;
//     }
// };