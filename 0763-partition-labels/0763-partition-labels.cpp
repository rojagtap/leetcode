/*
use last index of each character
start from 0 and try to finish the last index of s[0]
meanwhile whatever characters are added, finish them as well
if finished, move ahead with new partition
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastindex(26);
        for (int i = 0; i < s.size(); ++i) {
            lastindex[s[i] - 'a'] = i;
        }

        int stop = 0;
        vector<int> parts;
        int partitionsize = 0;
        for (int i = 0; i < s.size(); ++i) {
            ++partitionsize;
            stop = max(stop, lastindex[s[i] - 'a']);
            if (i == stop) {
                parts.push_back(partitionsize);
                partitionsize = 0;
            }
        }

        return parts;
    }
};