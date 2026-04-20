class Solution {
public:
    int longestBalanced(string& s) {
        int n = s.size();
        
        int count0 = 0, count1 = 0;
        vector<int> prefix1(n), prefix0(n), diff(n);
        for (int i = 0; i < n; ++i) {
            count0 += (s[i] == '0');
            count1 += (s[i] == '1');

            prefix1[i] = count1;
            prefix0[i] = count0;

            // this is actually the prefix sum of diff
            diff[i] = count1 - count0;
        }

        count0 = count1 = 0;
        vector<int> suffix1(n), suffix0(n);
        for (int i = n - 1; i >= 0; --i) {
            suffix0[i] = count0;
            suffix1[i] = count1;

            count0 += (s[i] == '0');
            count1 += (s[i] == '1');
        }

        int longest = 0;
        unordered_map<int, int> lookup_earliest = {{0, -1}}, lookup_earliest_0, lookup_earliest_1;

        for (int right = 0; right < n; ++right) {
            int prefix = diff[right];

            if (lookup_earliest.count(prefix)) {
                // subset that is already balanced
                int left = lookup_earliest[prefix];
                longest = max(longest, right - left);
            }

            // +-2 because the length of the substring needs to be even

            if (lookup_earliest.count(prefix + 2)) {
                // we want substring diff -2 (substring has too many 0s)
                // so curr - prev = -2 => prev = curr + 2
                int left = lookup_earliest[prefix + 2];

                // now check if there is a 1 available outside the substring
                if ((left >= 0 && prefix1[left]) || suffix1[right]) {                    
                    longest = max(longest, right - left);
                } else if (lookup_earliest_1.count(prefix + 2)) {
                    // this checks for prefix + 2 with at least one one to the left
                    // this itself is not enough because we also need to check for the case where
                    // there is no one at the left but at least one in the right, hence the if above
                    left = lookup_earliest_1[prefix + 2];
                    longest = max(longest, right - left);
                }
            }

            if (lookup_earliest.count(prefix - 2)) {
                // same thing as above but for 0s

                int left = lookup_earliest[prefix - 2];
                
                if ((left >= 0 && prefix0[left]) || suffix0[right]) {
                    longest = max(longest, right - left);
                } else if (lookup_earliest_0.count(prefix - 2)) {
                    left = lookup_earliest_0[prefix - 2];
                    longest = max(longest, right - left);
                }
            }

            if (!lookup_earliest.count(prefix)) {
                lookup_earliest[prefix] = right;
            }

            if (!lookup_earliest_0.count(prefix) && prefix0[right]) {
                lookup_earliest_0[prefix] = right;
            }

            if (!lookup_earliest_1.count(prefix) && prefix1[right]) {
                lookup_earliest_1[prefix] = right;
            }
        }

        return longest;
    }
};