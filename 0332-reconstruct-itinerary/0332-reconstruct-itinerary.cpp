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