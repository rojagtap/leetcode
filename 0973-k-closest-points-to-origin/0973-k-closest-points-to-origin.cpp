/*
min heap with comparator comparing distance from origin
*/
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for (auto& point : points) {
            closest.push(point);
        }
        
        vector<vector<int>> kclosest;
        while (k--) {
            kclosest.push_back(closest.top()); closest.pop();
        }
        
        return kclosest;
    }
    
private:
    class compare {
        public:
        bool operator() (vector<int>& pointa, vector<int>& pointb) {
            int dista = pointa[0] * pointa[0] + pointa[1] * pointa[1];
            int distb = pointb[0] * pointb[0] + pointb[1] * pointb[1];
            
            return dista > distb;
        }
    };
    
    priority_queue<vector<int>, vector<vector<int>>, compare> closest;
};