/**
looking at the problem during the contest, i figured that we need to go from left to right
and whenever there is a dip, we need to fix it irrespective of what's ahead
for this, i thought about noting the left greater element for each element in the array
we typically do this using a monotonic stack.
now, one opearation is adding +x to a subarray so we can add x to the entire suffix
also, always adding +x to to the suffix from current position does not change the relative diffs
so we can just keep on calculating the diffs from the left big with the cumulative additions
until that left greater element and add the diffs to x if >= 0.

now later, looking at the solutions, i realize that while my solution is accurate,
the entire monotonic stack and left greater idea is redundant. in this case we only want to
consider the left greater if it is adjacent. and the reason lies in "the diffs are relative"
there are just two cases to consider for diffs:
1. nums = [..., 10, 9, 8, ...],
in this case, when we bump up 9, 8 also bumps by one, so when we go to 8, we only have to add one
2. nums = [..., 10, 8, 9, ...],
in this case, the left greater of 9 is 10 and not 8. however, when we bump 8, 9 is already covered

so basically we just need nums[i - 1] > nums[i], and not the entire left greater thing
**/

class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long x = 0, n = nums.size();

        for (int i = 1; i < n; ++i) {
            x += max(0, nums[i - 1] - nums[i]);
        }

        return x;
    }
};

// class Solution {
// public:
//     long long minOperations(vector<int>& nums) {
//         int n = nums.size();

//         stack<int> mono;
//         vector<int> leftbig(n, -1);

//         for (int i = 0; i < n; ++i) {
//             while (mono.size() && nums[mono.top()] < nums[i]) {
//                 mono.pop();
//             }
//             if (mono.size()) leftbig[i] = mono.top();
//             mono.push(i);
//         }

//         long long x = 0;
//         vector<long long> add(n);

//         for (int i = 0; i < n; ++i) {
//             add[i] = x;
//             if (leftbig[i] == -1) continue;

//             long long diff = (nums[leftbig[i]] + add[leftbig[i]]) - (x + nums[i]);

//             if (diff <= 0) {
//                 continue;
//             }

//             x += diff;
//             add[i] += diff;
//         }

//         return x;
//     }
// };