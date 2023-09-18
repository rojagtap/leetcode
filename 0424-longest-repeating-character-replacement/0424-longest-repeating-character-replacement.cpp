class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        
        int maxfreq = 0;
        int longest = 0;
        int l = 0, r = 0;
        for (; r < s.size(); ++r) {
            if (freq.find(s[r]) == freq.end()) {
                freq[s[r]] = 0;
            }
            ++freq[s[r]];
            
            
            maxfreq = max(maxfreq, freq[s[r]]);
            
            if (maxfreq + k < r - l + 1) {
                --freq[s[l]];
                ++l;
            }

            longest = max(longest, r - l + 1);
        }
        
        return longest;
    }
};