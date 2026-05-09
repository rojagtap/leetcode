/**
during the contest, initially i thought about bruteforce where you try all possible
combinations of shifting numbers that can be shifted and count the max.
there is a repeating pattern here. since the shifts go left, the max points from i to n
don't change irrespective what you have until i for a given number of shifts until i
i.e., we can take carry and i and either move the ith element to i - carry - nums[i] or skip
carry is basically the number of elements deleted so far.
after submitting, i realized that the above logic won't work for arrays with duplicates.
so i tried taking a visited array to see if the a given position was already filled.
the problem here is taking an entire visited state for 1e5 elements is not possible alongside
carry and i. so i tried taking a separate visited array and a separate cache which won't work

here's when the contest ended.

now after the contest, i check other people's solutions + chatgpt and it was LIS
but I was not sure how.

the solutions had a tuple of (diff, nums[i])'s and finding the LIS for these. it sounded fine.
but when thinking of this approach, i first thought it works because we always pick the smallest diff first since it has the least number of deletions. and from here, i spiraled:
first of all, the LIS approach is not about picking diffs in increasing order. i mean it does that but the approach is not about doing this. it's not about the order of deletions.
GPT's solution also included sorting by diff in ascending and nums by descending order which
made me think picking rightmost elements first is better because they affect fewer items to the right. which again, is about order when it shouldn't be.
second, this led me into thinking about all sorts of scenarios like:
- what happens if i delete a number which could have been placed to it's spot?
- assuming the diff and current position i as an interval, what if two intervals overlap?
full overlaps are still ok, how do you handle partial overlaps? which one goes first? (again order)
- what if the shortest diff interval overlaps with two such intervals where we could have picked both if not for the shortest?
missing the fundamental LIS concept.
after taking this up with chatgpt further,
i realized that we can think about the problem like this:
for any two numbers x (at i) and y (at j) where x < y, to be able to pick both,
if i < j:
then diffx <= diffy because y shifts more (once for x and then for itself)
if i > j:
then it's not possible to pick both
so this tells me that to get multiple fixed points, i need to get points that are
a. increasing in value
b. increasing in diff
that's LIS with one value sorted and other LIS.
**/

class Solution {
public:
    int maxFixedPoints(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> tuples;
        for (int i = 0; i < n; ++i) {
            if (i - nums[i] >= 0) {
                tuples.push_back({i - nums[i], nums[i]});
            }
        }

        sort(begin(tuples), end(tuples));

        vector<int> lis;

        for (auto& [diff, num] : tuples) {
            auto it = lower_bound(begin(lis), end(lis), num);

            if (it == end(lis)) {
                lis.push_back(num);
            } else {
                *it = num;
            }
        }

        return lis.size();
    }
};

// class Solution {
// public:
//     int maxFixedPoints(vector<int>& nums) {
//         cache.resize(nums.size());
//         visited.assign(nums.size(), 0);
//         return dfs(nums, 0, 0);
//     }

// private:
//     vector<bool> visited;
//     vector<unordered_map<int, int>> cache;

//     int dfs(vector<int>& nums, int i, int carry) {
//         if (i == nums.size()) {
//             return 0;
//         }

//         if (cache[i].count(carry)) {
//             return cache[i][carry];
//         }

//         int fixed = 0;

//         if (!visited[nums[i]] && i - carry >= nums[i]) {
//             visited[nums[i]] = 1;
//             fixed = max(fixed, 1 + dfs(nums, i + 1, carry + (i - carry -
//             nums[i]))); visited[nums[i]] = 0;
//         }

//         fixed = max(fixed, dfs(nums, i + 1, carry));

//         return cache[i][carry] = fixed;
//     }
// };