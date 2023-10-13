/*
this is called a minimum spanning tree (MST) and there are two well known algorithms to traverse it
1. prim's
2. kruskal's

in prim's, we start from any vertex and look for the least weigheing edge from that vertex. the next vertex should not be in the existing graph or it will be a cycle.
this is a greedy algorithm and it's complexity is O(V^2) for array implementation as finding the least weight edge will be O(V) worst case and O(E + VlogV) E for populating adjacency with edges and VlogV for going to each vertex once and popping the least weighing vertex

whereas in kruskal's traverses edge by edge small to large until both vertices are already in the graph (cycle)
the complexity of kruskal's is (ElogE)

in cases where V >>> E, we use kruskal's whereas if E >>> V, we use prim's

in this case, E = V^2, so we will use prim's
*/
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int traversed = 1;
        int v = points.size();
        vector<bool> visited(v, false);

        // all vertices have the same adjacency, except itself
        // hence, we can update the same list for min distance so far
        vector<int> mindist(v, INT_MAX);

        int weight = 0;
        int currnode = 0;
        while (traversed < v) {
            visited[currnode] = true;
            for (int i = 0; i < v; ++i) {
                int distance = abs(points[i][0] - points[currnode][0]) + abs(points[i][1] - points[currnode][1]);
                if (!visited[i] && distance < mindist[i]) {
                    mindist[i] = distance;
                }
            }

            int minnode = -1;
            int minnodedist = INT_MAX;
            for (int i = 0; i < v; ++i) {
                if (!visited[i] && mindist[i] < minnodedist) {
                    minnode = i;
                    minnodedist = mindist[i];
                }
            }

            ++traversed;
            currnode = minnode;
            weight += minnodedist;
        }

        return weight;
    }
};