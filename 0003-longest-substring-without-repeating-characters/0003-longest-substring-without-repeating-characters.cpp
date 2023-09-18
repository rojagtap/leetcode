/*
sliding window

take a set for tracking the seen characters
take left and right pointer for array
if character does not exist in the set add to set
if exists, update maxlen and remove all characters from left to indexof(seen character) from the set. also left = indexof(seen character) + 1
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        
        int l = 0, r = 0;
        int longest = 0;
        for(; r < s.size(); ++r) {
            if (seen.find(s[r]) == seen.end()) {
                seen.insert(s[r]);
            } else {
                longest = max(longest, r - l);
                while (s[l] != s[r]) {
                    seen.erase(s[l]);
                    ++l;
                }
                ++l;
            }
        }
        
        return max(longest, r - l);
    }
};