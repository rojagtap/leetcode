/*
this problem can also be solved mathematically

two things can happen:
1. the frequency of the highest frequency task is so high that all the tasks will complete execution and only this task will run with idle
for example: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
2. low frequency tasks are a lot more than the highest frequency task can span
for example: tasks = ["A","A","A","A","B","B","C","D","E","F","G", "H", "I"], n = 2
A -> B -> C -> A -> B -> D -> A -> E -> F -> A -> G -> H -> I
note that there is no idle time here as GHI can execute back to back, i.e., n represents the cooldown period between two same tasks

now for 1, the output is freq(A) * n
and for 2, the example execution is more or less the same tasks array executed in a different order, so the output is tasks.size()

so we return max(max(freq) * n, tasks.size())
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        
        int maxfreq = 0;
        for (auto& task : tasks) {
            if (freq.find(task) == freq.end()) {
                freq[task] = 0;
            }
            ++freq[task];
            maxfreq = max(maxfreq, freq.at(task));
        }
        
        // maxfreq - 1 because it will be counted in the below loop
        int freqtime = (maxfreq - 1) * (n + 1);
        for (auto& entry : freq) if (entry.second == maxfreq) ++freqtime;
        
        return max(freqtime, (int) tasks.size());
    }
};

// /*
// first get the frequency table for all tasks (task with highest frequency starts first)
// use heap for having (freq, value) in descending order
// use the top value and put it to a queue for using waiting for n time units
// do this for n times
// then get back the queue tasks to the heap until the time - queue[0] is n (i.e., n units have elapsed since queue[0]'s execution)
// repeat this until heap and/or queue is empty
// */
// class Solution {
// public:
//     int leastInterval(vector<char>& tasks, int n) {
//         unordered_map<char, int> freq;
//         for (auto& task : tasks) {
//             if (freq.find(task) == freq.end()) {
//                 freq[task] = 0;
//             }
//             ++freq[task];
//         }

//         for (auto& entry : freq) taskpriority.push(make_pair(entry.second, entry.first));

//         int time = 0;
//         while (!taskpriority.empty() || !waitingq.empty()) {
//             ++time;

//             if (!taskpriority.empty()) {
//                 pair<int, char> executable = taskpriority.top(); taskpriority.pop();
//                 --executable.first;
//                 if (executable.first) waitingq.push(make_pair(time, executable));
//             }

//             if (!waitingq.empty() && (time - waitingq.front().first) == n) {
//                 pair<int, pair<int, char>> ready = waitingq.front(); waitingq.pop();
//                 taskpriority.push(ready.second);
//             }
//         }

//         return time;
//     }

// private:
//     class compare {
//         public:
//         bool operator() (pair<int, char> a, pair<int, char> b) {
//             return a.first < b.first;
//         }
//     };

//     priority_queue<pair<int, char>, vector<pair<int, char>>, compare> taskpriority;
//     queue<pair<int, pair<int, char>>> waitingq;
// };
