/*
dijkstra's from k to all nodes and keep the shortest path to all
if any node is not visited, return -1
*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adjacency(n + 1);
        for (auto& time : times) {
            adjacency[time[0]].push_back({time[1], time[2]});
        }

        vector<int> mintime(n + 1, INT_MAX);
        mintime[k] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minnext;

        minnext.push({0, k});
        while (!minnext.empty()) {
            k = minnext.top()[1];
            int currtime = minnext.top()[0];
            minnext.pop();

            if (mintime[k] < currtime) {
                // because heap has duplicates contrary to mintime which overwrites the shortest
                // path for each vertex
                // this condition means there is an old residual entry for the node k in heap
                continue;
            }

            for (auto& time : adjacency[k]) {
                // we don't need a visited marker because
                // the basic assumption of dijkstra's is 
                // if we traverse the shortest path from A -> D via B
                // then B -> D will also be the shortest path from B
                // hence it will never be possible that an already visited node
                // will have a shorter path than existing
                if (mintime[k] + time[1] < mintime[time[0]]) {
                    mintime[time[0]] = mintime[k] + time[1];
                    minnext.push({mintime[time[0]], time[0]});
                }
            }
        }

        int time = *max_element(mintime.begin() + 1, mintime.end());
        return time == INT_MAX ? -1 : time;
    }
};