/*
input: temperatures = [73, 74, 75, 71, 69, 72, 76, 73]

today is the iterator for temperatures
days is the stack for tracking the un-warmed day temperatures
daysUntilWarm is the result array containing the days taken for each day to see a warmer day than itself

today = 0   days = []           days.push(0)                            daysUntilWarm = [0, 0, 0, 0, 0, 0, 0, 0]
today = 1   days = [0]          days.pop(), days.push(1)                daysUntilWarm = [1, 0, 0, 0, 0, 0, 0, 0]
today = 2   days = [1]          days.pop(), days.push(2)                daysUntilWarm = [1, 1, 0, 0, 0, 0, 0, 0]
today = 3   days = [2]          days.push(3)                            daysUntilWarm = [1, 1, 0, 0, 0, 0, 0, 0]
today = 4   days = [2, 3]       days.push(4)                            daysUntilWarm = [1, 1, 0, 0, 0, 0, 0, 0]
today = 5   days = [2, 3, 4]    days.pop(), days.pop(), days.push(5)    daysUntilWarm = [1, 1, 0, 2, 1, 0, 0, 0]
today = 6   days = [2, 5]       days.pop(), days.pop(), days.push(6)    daysUntilWarm = [1, 1, 4, 2, 1, 1, 0, 0]
today = 7   days = [6]          days.push(7)                            daysUntilWarm = [1, 1, 4, 2, 1, 1, 0, 0]
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> days;
        vector<int> daysUntilWarm(temperatures.size(), 0);

        for (int today = 0; today < temperatures.size(); ++today) {
            while (!days.empty() && temperatures[days.top()] < temperatures[today]) {
                int top = days.top();
                daysUntilWarm[top] = today - top;
                days.pop();
            }
            days.push(today);
        }

        return daysUntilWarm;
    }
};