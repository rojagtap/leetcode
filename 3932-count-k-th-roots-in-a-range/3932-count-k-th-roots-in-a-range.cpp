/**
i had no problems arriving at a solution here, simple bruteforce
i also spent some time considering if there is any more optimal approach like sieve because the constraints were l, r <= 1e9 and k <= 30, but the bruteforce works well and i think is the only working solution
one minor miss during implementation was that i took x and y both between l and r, but only y is between l and r.
so i simply modified the range and it was good to go.
**/

class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if (k == 0) return 1;
        if (k == 1) return r - l + 1;

        int count = 0;

        for (int i = 0; i <= r; ++i) {
            long long y = pow(i, k);
            count += (y >= l && y <= r);
            if (y > r) break;
        }

        return count;
    }
};