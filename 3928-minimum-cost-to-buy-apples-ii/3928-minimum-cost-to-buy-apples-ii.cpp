/**
after reading the question i quickly realized this is multi-source shortest path
but we have a round trip so we can have a forward path and a backward path where
forwards consist of the costs and the backwards consist of tax * cost.
since it was a multi-source, my natural inclination was floyd-warshal's which i did implement
however it gave me TLE, so i did optimizations like combining the separate loop for mincost into the floyd warshal loop, eliminating the self edge loop, etc. but no luck
finally, i tried using dijkstra's and it worked. the trick was in the constraints:
roads.length <= min(n × (n - 1) / 2, 2000), so it's a sparse graph, a dense graph will have n^2 edges, which will be best solved by floyd warshal's but in this case dijkstra's wins.
this was a bit atypical for a leetcode contest, but this was something i knew i guess but i forgot and couldn't apply.
**/

class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<tuple<int, long long, long long>>> adj(n);
        for (auto& road : roads) {
            int u = road[0], v = road[1], cost = road[2], tax = road[3];
            adj[u].push_back({v, cost, 1LL * cost * tax});
            adj[v].push_back({u, cost, 1LL * cost * tax});
        }

        auto dijkstra = [&] (int source, bool isforward) {
            vector<long long> distance(n, LLONG_MAX);
            priority_queue<pair<long long, int>,
                vector<pair<long long, int>>, greater<>> traversal;
            
            distance[source] = 0;
            traversal.push({0, source});
            
            while (traversal.size()) {
                auto [dist, curr] = traversal.top();
                traversal.pop();

                if (dist > distance[curr]) continue;

                for (auto& [next, forward, backward] : adj[curr]) {
                    long long weight = isforward ? forward : backward;
                    if (dist + weight < distance[next]) {
                        distance[next] = dist + weight;
                        traversal.push({distance[next], next});
                    }
                }
            }

            return distance;
        };

        vector<int> mincost(prices.begin(), prices.end());

        for (int from = 0; from < n; ++from) {
            vector<long long> forward = dijkstra(from, true);
            vector<long long> backward = dijkstra(from, false);

            for (int to = 0; to < n; ++to) {
                if (forward[to] == LLONG_MAX || backward[to] == LLONG_MAX) {
                    continue;
                }

                long long price = (long long) prices[to] + forward[to] + backward[to];
                if (price < mincost[from]) {
                    mincost[from] = (int) price;
                }
            }
        }
        
        return mincost;
    }
};

/**
// tle, for a big test case
class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<int> mincost(begin(prices), end(prices));

        vector<vector<long long>> forward(n, vector<long long>(n, LLONG_MAX));
        vector<vector<long long>> backward(n, vector<long long>(n, LLONG_MAX));

        for (auto& road : roads) {
            int u = road[0], v = road[1], cost = road[2], tax = road[3];

            forward[u][v] = cost;
            forward[v][u] = cost;
            backward[u][v] = cost * tax;
            backward[v][u] = cost * tax;
            mincost[u] = min(mincost[u], prices[v] + (int) forward[u][v] + (int) backward[v][u]);
            mincost[v] = min(mincost[v], prices[u] + (int) forward[v][u] + (int) backward[u][v]);
        }

        for (int via = 0; via < n; ++via) {
            forward[via][via] = 0;
            backward[via][via] = 0;

            for (int from = 0; from < n; ++from) {
                for (int to = from + 1; to < n; ++to) {
                    if (forward[from][via] != LLONG_MAX && forward[via][to] != LLONG_MAX) {
                        if (forward[from][via] + forward[via][to] < forward[from][to]) {
                            forward[from][to] = forward[from][via] + forward[via][to];
                        }
                    }

                    if (backward[from][via] != LLONG_MAX && backward[via][to] != LLONG_MAX) {
                        if (backward[from][via] + backward[via][to] < backward[from][to]) {
                            backward[from][to] = backward[from][via] + backward[via][to];
                        }
                    }

                    if (forward[to][via] != LLONG_MAX && forward[via][from] != LLONG_MAX) {
                        if (forward[to][via] + forward[via][from] < forward[to][from]) {
                            forward[to][from] = forward[to][via] + forward[via][from];
                        }
                    }

                    if (backward[to][via] != LLONG_MAX && backward[via][from] != LLONG_MAX) {
                        if (backward[to][via] + backward[via][from] < backward[to][from]) {
                            backward[to][from] = backward[to][via] + backward[via][from];
                        }
                    }

                    if (forward[from][to] != LLONG_MAX && backward[to][from] != LLONG_MAX) {
                        mincost[from] = min(mincost[from], prices[to] + (int) forward[from][to] + (int) backward[to][from]);
                    }

                    if (forward[to][from] != LLONG_MAX && backward[from][to] != LLONG_MAX) {
                        mincost[to] = min(mincost[to], prices[from] + (int) forward[to][from] + (int) backward[from][to]);
                    }
                }
            }
        }

        return mincost;
    }
};

// tle, prices = [1,1,1], roads = [[0,1,1000000000,100],[1,2,1000000000,100]]
class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<long long>> forward(n, vector<long long>(n, LLONG_MAX));
        vector<vector<long long>> backward(n, vector<long long>(n, LLONG_MAX));

        for (int node = 0; node < n; ++node) {
            forward[node][node] = 0;
            backward[node][node] = 0;
        }

        for (auto& road : roads) {
            int u = road[0], v = road[1], cost = road[2], tax = road[3];

            forward[u][v] = cost;
            forward[v][u] = cost;
            backward[u][v] = cost * tax;
            backward[v][u] = cost * tax;
        }

        for (int via = 0; via < n; ++via) {
            for (int from = 0; from < n; ++from) {
                for (int to = 0; to < n; ++to) {
                    if (forward[from][via] != LLONG_MAX && forward[via][to] != LLONG_MAX) {
                        if (forward[from][via] + forward[via][to] < forward[from][to]) {
                            forward[from][to] = forward[from][via] + forward[via][to];
                        }
                    }

                    if (backward[from][via] != LLONG_MAX && backward[via][to] != LLONG_MAX) {
                        if (backward[from][via] + backward[via][to] < backward[from][to]) {
                            backward[from][to] = backward[from][via] + backward[via][to];
                        }
                    }
                }
            }
        }

        vector<int> mincost(n);

        for (int from = 0; from < n; ++from) {
            mincost[from] = prices[from];

            for (int to = 0; to < n; ++to) {
                if (forward[from][to] != LLONG_MAX && backward[from][to] != LLONG_MAX) {
                    mincost[from] = min(mincost[from], prices[to] + (int) forward[from][to] + (int) backward[to][from]);
                }
            }
        }

        return mincost;
    }
};

// wa, prices = [4,3], roads = []
class Solution {
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<long long>> forward(n, vector<long long>(n, LLONG_MAX));
        vector<vector<long long>> backward(n, vector<long long>(n, LLONG_MAX));

        for (int node = 0; node < n; ++node) {
            forward[node][node] = 0;
            backward[node][node] = 0;
        }

        for (auto& road : roads) {
            int u = road[0], v = road[1], cost = road[2], tax = road[3];

            forward[u][v] = cost;
            forward[v][u] = cost;
            backward[u][v] = cost * tax;
            backward[v][u] = cost * tax;
        }

        for (int via = 0; via < n; ++via) {
            for (int from = 0; from < n; ++from) {
                for (int to = 0; to < n; ++to) {
                    if (forward[from][via] != LLONG_MAX && forward[via][to] != LLONG_MAX) {
                        if (forward[from][via] + forward[via][to] < forward[from][to]) {
                            forward[from][to] = forward[from][via] + forward[via][to];
                        }
                    }

                    if (backward[from][via] != LLONG_MAX && backward[via][to] != LLONG_MAX) {
                        if (backward[from][via] + backward[via][to] < backward[from][to]) {
                            backward[from][to] = backward[from][via] + backward[via][to];
                        }
                    }
                }
            }
        }

        vector<int> mincost(n);

        for (int from = 0; from < n; ++from) {
            mincost[from] = prices[from];

            for (int to = 0; to < n; ++to) {
                mincost[from] = min(mincost[from], prices[to] + (int) forward[from][to] + (int) backward[to][from]);
            }
        }

        return mincost;
    }
};
**/