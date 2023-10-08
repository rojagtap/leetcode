/*
intervals is sorted and non overlapping
for the new interval there are 3 possible cases:
case 1: fits in without issues
case 2: lies between starti and endi so no changes required
case 2: need to merge the next intervals (starti < startnew < endi and startj < endnew < endj)
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> merged;

        int i = 0;
        while (i < intervals.size() && newInterval[0] > intervals[i][1]) {
            merged.push_back(intervals[i]);
            ++i;
        }

        while (i < intervals.size() && newInterval[1] >= intervals[i][0]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        
        merged.push_back(newInterval);

        while (i < intervals.size()) {
            merged.push_back(intervals[i]);
            ++i;
        }
        
        return merged;
    }
};