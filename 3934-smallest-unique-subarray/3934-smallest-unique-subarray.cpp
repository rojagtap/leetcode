/**
i quickly, intuitively figured out that this a binary search over a monotonic solution set
"minimum possible length" was the hook for this i believe but i had to prove that this is monotonic
proof too came pretty quickly that if you find a subarray of length n that is unique, then you add anything to it, it will be unique, so the solution space is monotonic, so binary search is approved
now i was considering if there was an even better approach that directly gets you the smallest unique subarray. but there isn't as you'll have to try all subarrays which is O(n^2 + check).
now to the checks, i was considering having the subarray serialized to a string and then putting it to a hash map of counts. but each hashing operation itself is O(n), so total is O(n^2) which gives O(n^2 logn), mostly not acceptable not sure because it is not exactly n^2.
in the interest of time, i actually started implementing this solution to later realize that handling the string serialization is a bit tricky.
i was still thinking in my head if there was a way to do this entire thing in a O(n).
in sometime (not much, reasonable tbh), it clicked, rolling hash! i knew how those work in principle-- basically it has the property of prefix arrays (not sure what it's called, invertible i guess), but i didn't know how to implement it on the spot, so i took the standard rolling hash from gpt (i think that's not cheating).
**/

using ull = unsigned long long;

struct RollingHash {
    int n;
    ull base = 100001;  // > max element
    vector<ull> hash, power;

    RollingHash(const vector<int>& a) {
        n = a.size();
        hash.resize(n + 1, 0);
        power.resize(n + 1, 1);

        for (int i = 0; i < n; i++) {
            hash[i + 1] = hash[i] * base + (a[i] + 1); 
            power[i + 1] = power[i] * base;
        }
    }

    // get hash of subarray [l, r]
    ull get(int l, int r) {
        return hash[r + 1] - hash[l] * power[r - l + 1];
    }
};

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        RollingHash func(nums);

        int low = 1, high = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (check(nums, mid, func)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

private:
    bool check(vector<int>& nums, int k, RollingHash& func) {
        unordered_map<ull, int> freq;

        for (int i = 0; i < nums.size(); ++i) {
            if (i + 1 >= k) {
                ++freq[func.get(i + 1 - k, i)];
            }
        }

        for (auto& [_, count] : freq) {
            if (count == 1) return true;
        }

        return false;
    }
};