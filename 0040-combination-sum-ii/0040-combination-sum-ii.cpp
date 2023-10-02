/*
very similar to https://leetcode.com/problems/combination-sum/
everything is same except, to handle duplicates
if the previous element is the same as current, skip taking the element as pivot
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> combination;
        recurse(candidates, combination, target, 0, 0);

        return combinations;
    }

private:
    vector<vector<int>> combinations;

    void recurse(vector<int>& candidates, vector<int>& combination, int& target, int currsum, int startindex) {
        if (currsum == target) combinations.push_back(combination);

        if (startindex == candidates.size() || currsum >= target) return;

        for (int i = startindex; i < candidates.size(); ++i) {
            if (i == startindex || candidates[i - 1] != candidates[i]) {
                combination.push_back(candidates[i]);
                recurse(candidates, combination, target, currsum + candidates[i], i + 1);
                combination.pop_back();
            }
        }
    }
};