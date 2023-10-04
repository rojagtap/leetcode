/*
*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = 0;
        for (auto& edge : edges) {
            n = max({n, edge[0], edge[1]});
        }
        
        vector<int> disjointset (n + 1, -1);
        for (auto& edge : edges) {
            if (disjointset[edge[0]] == -1 && disjointset[edge[1]] == -1) {
                disjointset[edge[0]] = -2;
                disjointset[edge[1]] = edge[0];
            } else if (disjointset[edge[0]] == -1) {
                int idx = edge[1];
                while (disjointset[idx] > 0) {
                    idx = disjointset[idx];
                }
                disjointset[idx] += (-1);
                disjointset[edge[0]] = edge[1];
            } else if (disjointset[edge[1]] == -1) {
                int idx = edge[0];
                while (disjointset[idx] > 0) {
                    idx = disjointset[idx];
                }
                disjointset[idx] += (-1);
                disjointset[edge[1]] = edge[0];
            } else {                
                int idx0 = edge[0];
                while (disjointset[idx0] > 0) {
                    idx0 = disjointset[idx0];
                }
                
                int idx1 = edge[1];
                while (disjointset[idx1] > 0) {
                    idx1 = disjointset[idx1];
                }
                
                if (idx0 == idx1) {
                    return edge;
                }
                
                if (disjointset[idx0] <= disjointset[idx1]) {
                    disjointset[idx0] += disjointset[idx1];
                    disjointset[idx1] = idx0;
                } else {
                    disjointset[idx1] += disjointset[idx0];
                    disjointset[idx0] = idx1;
                }
            }
        }
        
        return vector<int>();
    }
};