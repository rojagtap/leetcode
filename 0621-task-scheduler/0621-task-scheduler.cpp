/*
first get the frequency table for all tasks (task with highest frequency starts first)
use heap for having (freq, value) in descending order
use the top value and put it to a queue for using waiting for n time units
do this for n times
then get back the queue tasks to the heap until the time - queue[0] is n (i.e., n units have elapsed since queue[0]'s execution)
repeat this until heap and/or queue is empty
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for (auto& task : tasks) {
            if (freq.find(task) == freq.end()) {
                freq[task] = 0;
            }
            ++freq[task];
        }

        for (auto& entry : freq) taskpriority.push(make_pair(entry.second, entry.first));

        int time = 0;
        while (!taskpriority.empty() || !waitingq.empty()) {
            ++time;

            if (!taskpriority.empty()) {
                pair<int, char> executable = taskpriority.top(); taskpriority.pop();
                --executable.first;
                if (executable.first) waitingq.push(make_pair(time, executable));
            }

            if (!waitingq.empty() && (time - waitingq.front().first) == n) {
                pair<int, pair<int, char>> ready = waitingq.front(); waitingq.pop();
                taskpriority.push(ready.second);
            }
        }

        return time;
    }

private:
    class compare {
        public:
        bool operator() (pair<int, char> a, pair<int, char> b) {
            return a.first < b.first;
        }
    };

    priority_queue<pair<int, char>, vector<pair<int, char>>, compare> taskpriority;
    queue<pair<int, pair<int, char>>> waitingq;
};
