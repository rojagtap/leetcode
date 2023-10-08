/*
first sort intervals in descending order of starts (can also use queue and sort ascending)
also sort queries
then for each query:
    pop out the intervals that start before this query and push them to a heap
    the heap is a min heap sorted by r - l + 1 of each interval popped out
    once done,
    pop out all the heap tops where the end < query (i.e., all the intervals not consisting the query. now since query is sorted, these intervals are anyway not going to be used)
    now the heap will only have intervals (and ranges) to which the query belongs and in the order of lowest to highest range
    take the top and add it to the result
*/
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        unordered_map<int, int> querytorange;

        vector<int> sortedqueries(queries.begin(), queries.end());
        sort(sortedqueries.begin(), sortedqueries.end());

        sort(intervals.begin(), intervals.end(), greater<vector<int>>());

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> smallrange;

        for (auto& query : sortedqueries) {
            while (!intervals.empty() && intervals.back()[0] <= query) {
                vector<int> interval = intervals.back();
                smallrange.push({interval[1] - interval[0] + 1, interval[1]});
                intervals.pop_back();
            }

            while (!smallrange.empty() && smallrange.top()[1] < query) {
                smallrange.pop();
            }

            querytorange[query] = smallrange.empty() ? -1 : smallrange.top()[0];
        }
        
        vector<int> range;
        for (auto& query : queries) {
            range.push_back(querytorange[query]);
        }

        return range;
    }
};