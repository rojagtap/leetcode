/*
topological sort
solution is the traversal
*/
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, unordered_set<int>> adjacency;

        for (auto& prerequisite : prerequisites) {
            ++indegree[prerequisite[0]];
            adjacency[prerequisite[1]].insert(prerequisite[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        vector<int> traversal;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            traversal.push_back(node);

            for (auto& next : adjacency[node]) {
                --indegree[next];
                if (!indegree[next]) {
                    q.push(next);
                }
            }
        }

        return traversal.size() == numCourses ? traversal : vector<int>();
    }
};