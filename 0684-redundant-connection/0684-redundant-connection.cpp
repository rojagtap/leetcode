/*
to find the cycle, we do union join (https://www.youtube.com/watch?v=wU6udHRIkcc)

so the idea is we construct the graph bottom-up edge by edge
there are many disjoint graphs initially, but as edges come, we merge (union) them
for example: edges = [[1,2],[2,3],[3,4],[1,5],[1,4]]
    5 -> 1 <- 2 <- 3 <- 4
now in this graph if we get a new edge that joins any 2 vertices like [1,4]
then it is bound to create a cycle
(think about it, there is an existing structure of this graph which connects all the vertices (undirected), if we create a bypass between any 2 nodes, this will form a cycle)

to implement this,
we initialize an array of size n + 1 (all vertices 1-n) with value -1
as we construct the graphs, we will give the parent vertex's index in the child and the root will have -(# vertices in the graph)
for example: edges = [[3,4],[1,2],[2,4],[3,5],[2,5]]

first we take array [-1, -1, -1, -1, -1, -1]
first we see edge [3, 4] so we set 3 as root and 4 will point to 3
array will be       [-1, -1, -1, -2, 3, -1]     (4 will point to 3 and 3 will have -ve # of vertices)
next we see edge [1,2], new edge, so we set 1 as root and 2 will point to 1
array will be       [-1, -2, 1, -2, 3, -1]
next is [2,4], 2 already is in a graph and 4 is in a different graph, so we merge these graphs
the way to do this is 
1. go up until the root vertex of both graphs
2. higher # of vertices will stay the root and lower will become the subgraph
array will be       [-1, -4, 1, 1, 3, -1]       (notice that 3->4 edge got merged to 1->2)
next is edge [3,5], here 3 is already in a graph and 5 is not yet seen so we add 5 to the same graph
array will be       [-1, -4, 1, 1, 3, 3]
finally we have [2,5] both the vertices are in the same graph (i.e., they have the same root)
hence we return [2,5] as it will cause a cycle
*/
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
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