/*
for intervals = [[0,1],[1,3],[2,6],[8,10],[15,18]]
until intervals[0][1] >= intervals[0 + i][0] iterate ahead
once stopped insert the combined interval in new array
repeat this until i < size
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        sort(intervals.begin(), intervals.end());

        int i = 0;
        vector<int> coalesce = intervals[0];
        while (i < intervals.size()) {
            if (coalesce[1] >= intervals[i][0]) {
                coalesce[1] = max(coalesce[1], intervals[i][1]);
            } else {
                merged.push_back(coalesce);
                coalesce = intervals[i];
            }

            ++i;
        }
        
        merged.push_back(coalesce);
        return merged;
    }
};