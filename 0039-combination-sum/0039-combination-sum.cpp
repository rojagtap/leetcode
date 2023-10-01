class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        recurse(candidates, combination, 0, target, 0);
        
        return combinations;
    }
    
private:
    vector<vector<int>> combinations;
    
    void recurse(vector<int>& candidates, vector<int>& combination, int currsum, int& target, int currindex) {
        if (currsum == target) {
            combinations.push_back(vector<int>(combination.begin(), combination.end()));
        }
        
        if (currsum >= target) return;
        
        for (int i = currindex; i < candidates.size(); ++i) {
            combination.push_back(candidates[i]);
            recurse(candidates, combination, currsum + candidates[i], target, i);
            combination.pop_back();
        }
    }
};