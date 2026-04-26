class Solution {
public:
    string sortVowels(string& s) {
        int n = s.size();

        vector<int> pos;

        unordered_map<char, int> freqmap, idxmap;

        unordered_set<char> vowelset = {'a', 'e', 'i', 'o', 'u'};

        for (int i = 0; i < n; ++i) {
            if (vowelset.count(s[i])) {
                ++freqmap[s[i]];
                pos.push_back(i);

                if (!idxmap.count(s[i])) {
                    idxmap[s[i]] = i;
                }
            }
        }

        vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        sort(begin(vowels), end(vowels), [&] (const char& a, const char& b) {
            if (!freqmap.count(a)) return false;
            if (!freqmap.count(b)) return true;

            if (freqmap[a] == freqmap[b]) {
                return idxmap[a] < idxmap[b];
            }

            return freqmap[a] > freqmap[b];
        });

        int curr = 0;

        string sorted = s;

        for (auto& i : pos) {
            sorted[i] = vowels[curr];

            if (--freqmap[vowels[curr]] == 0) {
                ++curr;
            }
        }

        return sorted;
    }
};