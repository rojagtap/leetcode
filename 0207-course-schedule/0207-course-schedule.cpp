/*
this is a classic application of topological sort
based on a dependency graph it traverses the graph in the permitted order of execution
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, int> indegree;
        unordered_map<int, unordered_set<int>> adjacency;
        
        for (auto& prerequisite : prerequisites) {
            ++indegree[prerequisite[0]];
            adjacency[prerequisite[1]].insert(prerequisite[0]);
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int finished = 0;
        while (!q.empty()) {
            ++finished;
            int node = q.front();
            q.pop();

            for (auto& next : adjacency[node]) {
                --indegree[next];
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return finished == numCourses;
    }
};