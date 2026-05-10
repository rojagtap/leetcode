/**
first i cleared the problem:
since the nums are replaced by another from the array, there is no funny business
it's always going to be substituted with a number from the array
a naive factor search for each number is a reasonable O(n√m) where m = max(nums)
i didn't stress much on this and went ahead.
however, i see a faster solution (it probably wouldn't have clicked anyway)
since the nums are replaced by another from the array, we can sort and do a sieve for each number. this will be O(m log m) where m = max(nums)
however this is only better for nums[i] <= 1e5
for much larger values, nums[i] >= 1e9, the sieve is not feasible, we'd have to go for the factors approach
**/

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int m = *max_element(begin(nums), end(nums));

        vector<int> sieve(m + 1);
        iota(begin(sieve), end(sieve), 0);

        set<int> sorted(begin(nums), end(nums));
        for (auto& num : sorted) {
            if (sieve[num] == num) {
                for (int multiple = num; multiple <= m; multiple += num) {
                    if (sieve[multiple] == multiple) {
                        sieve[multiple] = num;
                    }
                }
            }
        }

        long long sum = 0;
        for (auto& num : nums) {
            sum += sieve[num];
        }

        return sum;
    }
};


// class Solution {
// public:
//     long long minArraySum(vector<int>& nums) {
//         unordered_set<long long> lookup(begin(nums), end(nums));

//         if (lookup.count(1)) return nums.size();

//         long long sum = accumulate(begin(nums), end(nums), 0LL);

//         for (auto& num : nums) {
//             long long smallest = num;

//             for (long long factor = 2; factor * factor <= num; ++factor) {
//                 if (num % factor > 0) continue;

//                 if (lookup.count(factor)) {
//                     smallest = factor;
//                     break;
//                 } else if (lookup.count(num / factor)) {
//                     smallest = min(smallest, num / factor);
//                 }
//             }

//             sum += smallest;
//             sum -= (long long) num;
//         }

//         return sum;
//     }
// };