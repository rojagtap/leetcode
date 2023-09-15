class Solution {
public:
    void generate(const string current, const int openCount, const int closeCount) {
        if (cache.find(make_tuple(current, openCount, closeCount)) != cache.end()) {
            return;
        } else {
            cache.insert(make_tuple(current, openCount, closeCount));
        }
        
        if (openCount == pairs && closeCount == pairs) {
            combinations.push_back(current);
            return;
        }
        
        if (openCount < pairs) {
            generate(current + "(", openCount + 1, closeCount);
        }
        if (closeCount < pairs && openCount > closeCount) {
            generate(current + ")", openCount, closeCount + 1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        pairs = n;
        generate("(", 1, 0);
        
        return combinations;
    }
    
private:
    int pairs;
    vector<string> combinations;
    set<tuple<string, int, int>> cache;
};