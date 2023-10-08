/*
consider the intervals sorted (by start and by end if starts equal)
if i and i + 1 overlap (i.e. if startiplus1 is between starti and endi)
then delete the one whose end is greater, this ensures that we delete the next one after this
only if it is not at all possible to keep it
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int deletions = 0;

        sort(intervals.begin(), intervals.end());

        int i = 1;
        vector<int> mininterval = intervals[0];
        while (i < intervals.size()) {
            if (mininterval[0] <= intervals[i][0] && intervals[i][0] < mininterval[1]) {
                ++deletions;
                if (mininterval[1] > intervals[i][1]) {
                    mininterval = intervals[i];
                }
            } else {
                mininterval = intervals[i];
            }

            ++i;
        }

        return deletions;
    }
};