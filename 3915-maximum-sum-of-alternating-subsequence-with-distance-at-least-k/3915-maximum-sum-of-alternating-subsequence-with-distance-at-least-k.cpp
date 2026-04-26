/**
looking at the problem, i first thought about the bruteforce
so the first thing is as simple as either you take the current num or you don't like a knapsack
if you take the current value, you go +k, or else, you go +1.
i also came to the realization that taking the kth value alone is not sufficient, we need to try
for all j >= i + k. now this can be achieved in two ways:

1. dfs(i, prev, up) -> max(for (j : i ... n) if (nums[i] > nums[prev]) dfs(i + k, nums[i], down))
and dfs(i, prev, down) -> max(for (j : i ... n)) if (nums[i] < nums[prev]) dfs(i + k, nums[i], up))
2. dfs(i, prev, up) -> max(if (nums[i] > prev) dfs(i + k, nums[i], down), dfs(i + 1, prev, up))
and dfs(i, prev, down) -> max(if (nums[i] < prev) dfs(i + k, nums[i], up), dfs(i + 1, prev, down))
(i just realized this one now)

looking at this bruteforce, i concluded that there are two axes,
- one is the "distance" (j >= i + k)
- and the other is max value (not score)
either of these cannot be picked greedily:
- if you always pick i + k, there might be a better outcome at i + k + x
- if you always pick the max value from i + k ... n, then you might miss out on two smaller
values that add up > max value
so basically, we need to check the max score we can get from all the positions from i + k ... n,
for all the values that are greater than (for up, or smaller for down) nums[i]

moreover, even with memoization and everything, this will still be O(n^2) i guess.
looking at the constraints, that doesn't seem to be acceptable.

now for the above two issues:
- for the range, we can easily accumulate all the results from i + k ... n at i + k,
so that we can just query some dp[up/down][i + k] that will give us the best result in i + k ... n
- for the max value, we need to basically find the max "score" we can achieve for any number
either from nums[i] + 1 to 1e5 for up, or 1 to nums[i] - 1 for down.
note that initially, i thought we have to keep all the values seen so far from n till j = i + k
in a sorted set so we can query the next greater value or the next smaller value than nums[i].
but i was wrong. since we are going in reverse (like in any dp) i.e. we are iterating n ... j,
we can simply try for nums[i] + 1 and - 1, because we only have results up till j.
so it doesn't matter if you query the next greater number or just nums[i] + 1.

all in all, we need to find a way to get the best score from j ... n,
across all numbers > nums[i] for up and < nums[i] for down
this is range query. we can use prefix/suffix arrays for 0 ... 1e5,
but the range updates are dynamic, so this is an use case for either segment tree or fenwick trees.
**/

class SegTree {
private:
    int n;
    static constexpr long long NEG = LLONG_MIN / 4;
    vector<long long> tree;

public:
    SegTree(int size) {
        n = size;
        tree.assign(4 * n + 4, NEG);
    }

    void update(int node, int l, int r, int pos, long long val) {
        if (l == r) {
            tree[node] = max(tree[node], val);
            return;
        }

        int mid = l + (r - l) / 2;

        if (pos <= mid) {
            update(2 * node, l, mid, pos, val);
        } else {
            update(2 * node + 1, mid + 1, r, pos, val);
        }

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int pos, long long val) {
        update(1, 1, n, pos, val);
    }

    long long query(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) {
            return NEG;
        }

        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = l + (r - l) / 2;

        return max(
            query(2 * node, l, mid, ql, qr),
            query(2 * node + 1, mid + 1, r, ql, qr)
        );
    }

    long long query(int l, int r) {
        if (l > r) return NEG;
        l = max(l, 1);
        r = min(r, n);
        return query(1, 1, n, l, r);
    }
};

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 4;

        SegTree up(1e5), down(1e5);

        vector<long long> upsum(begin(nums), end(nums)), downsum(begin(nums), end(nums));

        long long maxsum = 0;

        for (int right = n - 1; right >= 0; --right) {
            up.update(nums[right], upsum[right]);
            down.update(nums[right], downsum[right]);

            maxsum = max({maxsum, upsum[right], downsum[right]});

            int left = right - k;

            if (left < 0) continue;

            long long best_greater = down.query(nums[left] + 1, 1e5);
            if (best_greater != NEG) {
                upsum[left] += best_greater;
            }

            long long best_smaller = up.query(1, nums[left] - 1);
            if (best_smaller != NEG) {
                downsum[left] += best_smaller;
            }
        }

        return maxsum;
    }
};