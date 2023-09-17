/*
sliding window

left will be buy, right will be sell

if right is smaller than left, increment left
else update the maxprofit with right - left
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, maxprofit = INT_MIN;
        for (int right = 0; right < prices.size(); ++right) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                maxprofit = max(maxprofit, prices[right] - prices[left]);
            }
        }
        
        return maxprofit;
    }
};

// /*
// suffix max solution

// first pass:
// obtain the the max element max(prices[i + x]) to the right of each prices[i]

// second pass:
// take the best rightmax[i] - prices[i]
// */
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         vector<int> rightmax(prices.size());
        
//         rightmax.back() = prices.back();
//         for (int i = prices.size() - 2; i >= 0; --i) {
//             rightmax[i] = max(rightmax[i + 1], prices[i + 1]);
//         }
        
//         int maxprofit = 0;
//         for (int i = 0; i < prices.size(); ++i) {
//             maxprofit = max(maxprofit, rightmax[i] - prices[i]);
//         }
        
//         return maxprofit;
//     }
// };