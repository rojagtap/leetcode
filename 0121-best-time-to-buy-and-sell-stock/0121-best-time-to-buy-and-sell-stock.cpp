class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> rightmax(prices.size());
        
        rightmax.back() = prices.back();
        for (int i = prices.size() - 2; i >= 0; --i) {
            rightmax[i] = max(rightmax[i + 1], prices[i + 1]);
        }
        
        int maxprofit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            maxprofit = max(maxprofit, rightmax[i] - prices[i]);
        }
        
        return maxprofit;
    }
};