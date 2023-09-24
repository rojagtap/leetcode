class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq;
        for (auto& ch : t) {
            if (freq.find(ch) == freq.end()) {
                freq[ch] = 0;
            }
            ++freq[ch];
        }

        int matches = 0;
        int length = INT_MAX;
        int start = 0, end = 0;
        for (int l = 0, r = 0; r < s.size(); ++r) {
            if (freq.find(s[r]) != freq.end()) {
                --freq[s[r]];

                if (freq.at(s[r]) == 0) {
                    ++matches;
                }
            }

            while (matches == freq.size()) {
                if (r - l + 1 < length) {
                    length = r - l + 1;
                    start = l; end = r;
                }

                if (freq.find(s[l]) != freq.end()) {
                    if (freq.at(s[l]) == 0) --matches;
                    ++freq[s[l]];
                }

                ++l;
            }
        }

        return length == INT_MAX ? "" : s.substr(start, end - start + 1);
    }
};