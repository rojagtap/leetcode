/*
we can do a pseudo-bfs
start from n=end and look for all i that reach n take the min of them as it is closest to 0
then search for all the values that go until >= closest and take its min
repeat until n is 0

this can be O(n^2) as every time we search from 0 to n (for example [1,1,1,1,1,1,1,1])
but if we do the same thing in forward direction, it will be O(n)

start from 0
0 can go from 1 till nums[0]
so go from 1 to nums[0] and take the max reach, i.e., it will give the max this set can reach
now go from nums[0] + 1 to max and repeat
go until nums.size is the max or greater than that

we are pretty much doing the same thing in both approaches, just that since the direction of jumps is forward,
we can use that to search for the next level (in bfs) in linear time

this can be also solved using dp
the approach does the same as forward bfs
just that it will update the maxjump inplace in the nums array
*/

// // dp O(n)
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int jumps = 0;

//         for (int i = 1; i < nums.size(); ++i) {
//             nums[i] = max(nums[i - 1], i + nums[i]);
//         }

//         int i = 0;
//         while (i < nums.size() - 1) {
//             ++jumps;
//             i = nums[i];
//         }

//         return jumps;
//     }
// };

// forward bfs O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;

        int l = 0, r = 0;
        while (r < nums.size()) {
            if (r >= nums.size() - 1) {
                break;
            }

            int maxjump = INT_MIN;
            for (int j = l; j <= r; ++j) {
                maxjump = max(maxjump, j + nums[j]);
            }

            l = r + 1;
            r = maxjump;
            ++jumps;
        }

        return jumps;
    }
};

// reverse bfs O(n^2)
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int jumps = 0;
//         int n = nums.size() - 1;

//         int goal = n;
//         while (goal) {
//             int mingoal = INT_MAX;
//             for (int i = 0; i < n; ++i) {
//                 if (i + nums[i] >= goal) {
//                     mingoal = min(mingoal, i);
//                 }
//             }
//             goal = mingoal;
//             ++jumps;
//         }

//         return jumps;
//     }
// };