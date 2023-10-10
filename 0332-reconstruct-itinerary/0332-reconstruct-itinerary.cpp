/*
dfs but visit all edges
implementation is a bit tricky:
- multiple edges from A to B (multiset)
- next edge in adjacency must be sorted by lexicographic order (set instead of unordered)
- vertices might not have any outgoing edges

visited sets wont help as there can be multiple A to B edges
even if you use multisets, you cannot tell which one is visited

solution:
use multiset in adjacency, and use it like a queue
popping from front ensures that the edge isnt available for any other traversals
hence simulating visited
*/
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto& ticket : tickets) {
            adjacency[ticket[0]].insert(ticket[1]);
        }

        string src = "JFK";
        int ntickets = tickets.size();
        traverse(ntickets, src);

        reverse(path.begin(), path.end());

        return path;
    }

private:
    // set will sort values in lexicographic order
    unordered_map<string, multiset<string>> adjacency;

    vector<string> path;

    void traverse(int& ntickets, string& src) {
        while (!adjacency[src].empty()) {
            string dest = *adjacency[src].begin();
            adjacency[src].erase(adjacency[src].begin());

            traverse(ntickets, dest);
        }

        path.push_back(src);
    }
};