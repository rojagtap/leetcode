/*
sliding window

take a sliding window of length s1.size()
move it across s2 and add update matches and freq based on
new arrivals with ++r as well as characters leaving the window with ++l
if matches == freq.size() at any point, return true
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        for (auto& ch : s1) {
            if (freq.find(ch) == freq.end()) {
                freq[ch] = 0;
            }
            
            ++freq[ch];
        }
        
        int matches = 0;
        for (int r = 0, l = 0; r < s2.size(); ++r) {
            if (freq.find(s2[r]) != freq.end()) {
                --freq[s2[r]];
                if (freq[s2[r]] == 0) {
                    ++matches;
                }
            }
            
            if (r - l + 1 > s1.size()) {
                if (freq.find(s2[l]) != freq.end()) {
                    if (freq[s2[l]] == 0) {
                        --matches;
                    }
                    ++freq[s2[l]];
                }
                ++l;
            }
            
            if (matches == freq.size()) {
                return true;
            }
        }
        
        return false;
    }
};