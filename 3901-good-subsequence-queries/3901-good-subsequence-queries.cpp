class Solution {
public:
    int countGoodSubseq(vector<int>& nums, int p, vector<vector<int>>& queries) {
        int n = nums.size();

        // gcd will be p only for elements that are divisible by p

        unordered_map<int, int> freq;
        for (auto& num : nums) {
            if (num % p == 0) ++freq[num];
        }

        int count = 0;

        auto check = [&] () {
            int g = 0;
            for (auto& [num, count] : freq) {
                g = __gcd(g, num);
                if (g == p) return true;
            }
            return false;
        };

        auto checke = [&] () {
            // for (auto& [exclude, _] : freq) {
            //     int g = 0;
            //     for (auto& [num, count] : freq) {
            //         if (num == exclude) continue;
            //         g = __gcd(g, num);
            //         if (g == p) return true;
            //     }
            // }
            // the above can be achieved in O(n) using prefix-suffix gcd
            
            vector<int> uniq;
            for (auto& [num, _] : freq) {
                uniq.push_back(num);
            }

            int m = uniq.size();

            int g = 0;
            vector<int> prefix(m), suffix(m);

            for (int i = 0; i < m; ++i) {
                prefix[i] = g;
                g = __gcd(g, uniq[i]);
            }

            g = 0;

            for (int i = m - 1; i >= 0; --i) {
                suffix[i] = g;
                g = __gcd(g, uniq[i]);
            }

            for (int i = 0; i < m; ++i) {
                if (gcd(prefix[i], suffix[i]) == p) return true;
            }

            return false;
        };

        for (auto& query : queries) {
            int index = query[0], value = query[1];

            if (nums[index] % p == 0) {
                if (--freq[nums[index]] == 0) {
                    freq.erase(nums[index]);
                }
            }

            if (value % p == 0) {
                ++freq[value];
            }

            nums[index] = value;

            if (freq.size() < n) {
                // if there are less than n p-divisible numbers
                // we already know p is a common factor
                // and we want to remove other factors, so for gcd, more the merrier
                // check the entire set's gcd
                count += check();
            } else {
                // if there are n p-divisible number
                // we will have to try the above by excluding one element
                count += checke();
            }
        }

        return count;
    }
};