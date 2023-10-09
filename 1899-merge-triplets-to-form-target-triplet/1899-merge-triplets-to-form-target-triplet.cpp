/*
the basic observation here is

for a triplet, in the array, if any of the value at j is > target[j] where j = 0, 1, 2
then we cannot use this triplet. AT ALL

The reason is, for example, consider triplets = [[2,8,3],[1,5,4],[1,7,5]], target = [2,7,5]
here, even if we use the '2' from the first triplet for getting the target, given that there is an '8' at the second position which is > 7, and hence, this can NEVER be used to combine further to get the '7'.
*/
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> targetset;

        for (int i = 0; i < triplets.size(); ++i) {
            if (triplets[i][0] <= target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]) {
                for (int j = 0; j < 3; ++j) {
                    if (triplets[i][j] == target[j]) {
                        targetset.insert(j);
                    }
                }
            }
        }

        return targetset.size() == 3;
    }
};