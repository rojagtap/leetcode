/*
the bruteforce solution is to start from day 0
and try each day until we finally get m bouqets
this will be O((max - min) * n) where max is max(bloomDay)
instead we can try binary search on [min,max]
which will make the complexity O(log(max - min) * n)
*/
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        n = bloomDay.size();
        if (m > n / k) return -1;

        // left = min works because at least min days HAVE TO pass until we start counting
        int left = *min_element(bloomDay.begin(), bloomDay.end());
        int right = *max_element(bloomDay.begin(), bloomDay.end());
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

    bool mbouqets(vector<int>& bloomDay, int& m, int& k, int today) {
        int bouqets = 0, count = 0;
        for (auto day : bloomDay) {
            if (day > today) {
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