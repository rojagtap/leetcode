class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        n = bloomDay.size();
        if (m > n / k) return -1;

        int left = 0, right = *max_element(bloomDay.begin(), bloomDay.end());
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mbouqets(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left == right ? left : left - 1;
    }

private:
    int n;

    bool mbouqets(vector<int>& bloomDay, int& m, int& k, int day) {
        vector<bool> bloomed(n, false);
        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] <= day) {
                bloomed[i] = true;
            }
        }

        int bouqets = 0, count = 0;
        for (auto isbloomed : bloomed) {
            if (!isbloomed) {
                count = 0;
            } else {
                ++count;
                if (count == k) {
                    count = 0;
                    ++bouqets;
                    if (bouqets == m) return true;
                }
            }
        }

        return false;
    }
};