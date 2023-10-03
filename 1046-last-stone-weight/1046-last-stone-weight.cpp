/*
use max-heap
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        for (auto& stone : stones) {
            heavy.push(stone);
        }
        
        while (heavy.size() > 1) {
            int y = heavy.top(); heavy.pop();
            int x = heavy.top(); heavy.pop();
            
            if (y - x) heavy.push(y - x);
        }
        
        return heavy.empty() ? 0 : heavy.top();
    }

private:
    priority_queue<int> heavy;
};