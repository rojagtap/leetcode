/*
sliding window

keep left and right iterators
variable for tracking most frequent

iterate over right
if length of sequence (i.e., right - left) gets larger than most frequent + k, then slide the window (i.e. left++)
*/
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