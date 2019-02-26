/*
621. Task Scheduler
Medium

Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

 

Note:

    The number of tasks is in the range [1, 10000].
    The integer n is in the range [0, 100].
//Given a sequence of events and a cooling time k, what is the min length schedule?
//example: aaabbc, k = 3  abc-ab--a 
*/


/* Solution:
The idea is:
0. To work on the same task again, CPU has to wait for time n, therefore we can think of as if there is a cycle, of time n+1, regardless whether you schedule some other task in the cycle or not.

    To avoid leave the CPU with limited choice of tasks and having to sit there cooling down frequently at the end, it is critical the keep the diversity of the task pool for as long as possible.
    In order to do that, we should try to schedule the CPU to always try round robin between the most popular tasks at any time.
*/

// priority_queue<task, count>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for (char t : tasks) {
            counts[t]++;
        }
        priority_queue<pair<int, char>> pq;
        for (pair<char, int> count : counts) {
            pq.push(make_pair(count.second, count.first));
        }
        int alltime = 0;
        int cycle = n + 1;
        while (!pq.empty()) {
            int time = 0;
            vector<pair<int, char>> tmp;
            for (int i = 0; i < cycle; i++) {
                if (!pq.empty()) {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for (auto t : tmp) {
                if (--t.first) {
                    pq.push(t);
                }
            }
            alltime += !pq.empty() ? cycle : time;
        }
        return alltime;
    }
};

//priority_queue<count>
As @milu point out, we don't really need to store <task - count> pair in the priority_queue, we don't need to know the task name, store counts works good enough:

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> event_count(26,0);
        // 1. count each event
        for(char ch: tasks){
            event_count[ch-'A']++;
        }
        priority_queue<int>max_heap;
        for(int i = 0;i<26;i++){
            if(event_count[i])
                max_heap.push(event_count[i]);
        }
        int cycle = n+1;
        int allTime = 0;
        while(!max_heap.empty()){
            int time = 0;
            vector<int> tmp;
            for(int i = 0;i<cycle;i++){
                if(!max_heap.empty()){
                    tmp.push_back(max_heap.top());
                    max_heap.pop();
                    time++;
                }
            }
            for(int item : tmp){
                if(--item)
                    max_heap.push(item);
            }
            allTime+= !max_heap.empty()?cycle:time;
        }

        return allTime;
    }
};