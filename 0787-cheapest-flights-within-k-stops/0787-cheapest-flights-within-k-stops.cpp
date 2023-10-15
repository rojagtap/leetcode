/*
dijkstra's with stop limit
in heap we will have <k, cost, next>
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> mincost(n, INT_MAX);
        mincost[src] = 0;

        vector<vector<vector<int>>> adjacency(n);
        for (auto& flight : flights) {
            adjacency[flight[0]].push_back({flight[1], flight[2]});
        }

        // priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> q;
        queue<vector<int>> q;
        q.push({0, 0, src});

        while (!q.empty()) {
            int kpath = q.front()[0], cost = q.front()[1], city = q.front()[2];
            q.pop();

            if (kpath > k) continue;

            for (auto& next : adjacency[city]) {
                if (cost + next[1] < mincost[next[0]] && kpath <= k) {
                    mincost[next[0]] = cost + next[1];
                    q.push({kpath + 1, mincost[next[0]], next[0]});
                }
            }
        }

        return mincost[dst] == INT_MAX ? -1 : mincost[dst];
    }
};