/*
cost    = [3,4,5,1,2]
gas     = [1,2,3,4,5]
diff    = [-2,-2,-2,3,3]

in bruteforce, we start from start = 0 and if total < 0 we start again from start + 1
however if for some i the total < 0, all j < i dont really help, so we should move to start = i + 1 directly
also we don't need to verify the circular array till the end
it is given that there is a unique solution
so if all the solutions till now didnt work, this has to
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int start = 0, total = 0;
        for (int i = 0; i < gas.size(); ++i) {
            total += (gas[i] - cost[i]);
            
            if (total < 0) {
                total = 0;
                start = i + 1;
            }
        }
        
        return start;
    }
};