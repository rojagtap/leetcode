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