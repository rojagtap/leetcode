/*
guess a speed
count the number of hours for that speed
if hours <= h, then backup the speed and try reducing further
if hours > h, make a smaller guess

here for guessing, we use binary search
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minspeed = 1;
        int maxspeed = *max_element(piles.begin(), piles.end());
        
        int k = maxspeed;
        while (minspeed <= maxspeed) {
            int mid = minspeed + (maxspeed - minspeed) / 2;
            
            long hours = gethours(piles, mid, h);
            if (hours <= h) {
                k = min(k, mid);
                maxspeed = mid - 1;
            } else {
                minspeed = mid + 1;
            }
        }

        return k;
    }
    
private:
    long gethours(vector<int>& piles, int k, int h) {
        long hours = 0;
        for (auto& pile : piles) {
            hours += ceil(pile / (double) k);
        }
        
        return hours;
    }
};