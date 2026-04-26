class Solution {
public:
    string sortVowels(string& s) {
        int n = s.size();

        vector<int> pos;

        vector<int> freqmap(26), idxmap(26, -1);

        unordered_set<char> vowelset = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < n; ++i) {
            if (vowelset.count(s[i])) {
                pos.push_back(i);
                ++freqmap[s[i] - 'a'];

                if (idxmap[s[i] - 'a'] == -1) {
                    idxmap[s[i] - 'a'] = i;
                }
            }
        }

        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        sort(begin(vowels), end(vowels), [&] (const char& a, const char& b) {
            if (!freqmap[a - 'a']) return false;
            if (!freqmap[b - 'a']) return true;

            if (freqmap[a - 'a'] != freqmap[b - 'a']) {
                return freqmap[a - 'a'] > freqmap[b - 'a'];
            }

            return idxmap[a - 'a'] < idxmap[b - 'a'];
        });

        int curr = 0;

        string sorted = s;

        for (auto& i : pos) {
            sorted[i] = vowels[curr];

            if (--freqmap[vowels[curr] - 'a'] == 0) {
                ++curr;
            }
        }

        return sorted;
    }
};