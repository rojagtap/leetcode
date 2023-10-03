/*
create a map of node vs copynode
do a bfs on the graph and connect the subsequent edges
visited can be presence in the map
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        queue<Node*> q;
        q.push(node);
        
        mapping[node] = new Node(node->val);
        
        while (!q.empty()) {
            Node *curr = q.front();
            q.pop();
            
            for (auto& neighbor : curr->neighbors) {
                if (mapping.find(neighbor) == mapping.end()) {
                    mapping[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                
                mapping[curr]->neighbors.push_back(mapping.at(neighbor));
            }
        }
        
        return mapping[node];
    }

private:
    unordered_map<Node*, Node*> mapping;
};