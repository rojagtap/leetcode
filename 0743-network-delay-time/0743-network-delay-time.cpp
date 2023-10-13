/*
dijkstra's from k to all nodes and keep the shortest path to all
if any node is not visited, return -1
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<vector<int>>> adjacency;
        for (auto& time : times) {
            adjacency[time[0]].push_back({time[1], time[2]});
        }

        int visitedcount = 1;
        vector<bool> visited(n + 1, false);
        vector<int> mintime(n + 1, INT_MAX);

        mintime[0] = 0;
        mintime[k] = 0;
        while (visitedcount < n) {
            visited[k] = true;

            for (auto& time : adjacency[k]) {
                if (!visited[time[0]]) {
                    mintime[time[0]] = min(mintime[time[0]], mintime[k] + time[1]);
                }
            }

            int nextk = -1;
            int minnext = INT_MAX;
            for (int i = 1; i <= n; ++i) {
                if (!visited[i] && mintime[i] < minnext) {
                    minnext = mintime[i];
                    nextk = i;
                }
            }

            if (nextk == -1) return -1;
            k = nextk;
            ++visitedcount;
        }

        return *max_element(mintime.begin(), mintime.end());
    }
};