/*
sort and go from small to higher values
for each value i not already visited,
look for hand[i] + n where n ranges from 1 to groupSize
if it does not exist, return false
if exists, set that value to visited, so it is not considered again

even more efficient,
By default, a Map in C++ is sorted in increasing order based on its key
so can use map directly and traverse the map instead of separately sorting the array and and traversing the array

for hand = [1,2,3,6,2,3,4,7,8], groupSize = 3

sort = [1,2,2,3,3,4,6,7,8]
reverse = {
    1: [0],
    2: [1, 2],
    3: [3, 4],
    4: [5],
    6: [6],
    7: [7],
    8: [8]
}

i = 0:
    n = 1:
    back = 2
    sort = [1,2,-1,3,3,4,6,7,8]
    n = 2:
    back = 4
    sort = [1,2,-1,3,-1,4,6,7,8]
i = 1:
    n = 1:
    back = 3
    sort = [1,2,-1,-1,-1,4,6,7,8]
    n = 2:
    back = 5
    sort = [1,2,-1,-1,-1,-1,6,7,8]
i = 2:
    skip
...
...
i = 6:
    n = 1:
    back = 7
    sort = [1,2,-1,-1,-1,-1,6,-1,8]
    n = 2:
    back = 8
    sort = [1,2,-1,-1,-1,-1,6,-1,-1]
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        sort(hand.begin(), hand.end());

        unordered_map<int, vector<int>> reverse;
        for (int i = 0; i < hand.size(); ++i) {
            reverse[hand[i]].push_back(i);
        }

        for (int i = 0; i < hand.size(); ++i) {
            if (hand[i] == -1) continue;

            int n = 1;
            while(n < groupSize) {
                if (reverse[hand[i] + n].empty()) {
                    return false;
                }
                int back = reverse[hand[i] + n].back();
                reverse[hand[i] + n].pop_back();

                hand[back] = -1;
                ++n;
            }
        }

        return true;
    }
};