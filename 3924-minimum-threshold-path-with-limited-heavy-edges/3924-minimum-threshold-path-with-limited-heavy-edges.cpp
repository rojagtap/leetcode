/**
i immediately thought about binary search + dijkstra's
but (maybe because of contest countdown), i was not able to come up
with an idea to implement the dijkstra's such that we keep the heavy <= k
i was thinking about naive dijkstra's where i'd have to do a take/skip over edges > threshold
but that would've been very inefficient, so i was thinking about other strategies
one strategy i was thinking about was in the min/max direction (i actually needed minimax not pure min over min but didn't realize)
given that i am out of dedicated practice, i was struggling on whether dijkstra's works
on min/max. i concluded that it doesn't work on pure min/max as the local optimal path might
not be globally optimal. then i was going for floyd warshal if that works. it might.
but then i thought, if i am greedily going for the minimax, do i really need binary search?
i can just take the minimax path and skip largest k edges and that's my threshold.
but after the contest, when i asked chatgpt, i understood that this solution doesn't work. 
for example: Path A: [100, 1, 1, 1], Path B: [60, 60, 60]
the minimax path is path B. but k = 1 or 2 doesn't allow it, but it does for path A
and when i saw the binary search + 0/1 bfs, i understood the optimal way to solve it without the permutation issue
i think i was actually looking for some multi-objective dijkstra's idea but went here instead. i think i could've figured it out if practiced.
**/

class Solution {
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        auto bfs = [&] (int threshold) {
            deque<int> traversal;
            vector<int> dist(n, INT_MAX);

            dist[source] = 0;
            traversal.push_back(source);

            while (traversal.size()) {
                int u = traversal.front();
                traversal.pop_front();

                for (auto& [v, w] : adj[u]) {
                    int heavy = w > threshold ? 1 : 0;

                    if (heavy + dist[u] < dist[v]) {
                        dist[v] = heavy + dist[u];

                        // dist[curr] is the lowest so far
                        // so that + 0 is the next lowest so goes to front
                        if (heavy) {
                            traversal.push_back(v);
                        } else {
                            traversal.push_front(v);
                        }
                    }
                }
            }

            return dist[target] <= k;
        };

        int threshold = -1;
        int low = 0, high = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (bfs(mid)) {
                threshold = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return threshold;
    }
};