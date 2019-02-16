/*
253. Meeting room II
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] find the minimum number of conference rooms required.
 */
/*
- sort based on the start times
- sort the end times in a separate copy
- the idea is similar to merging two arrays in mergesort
- there are two pointers i pointing to the current element in the start array and j pointing to the current in the end element 
- if(start[i]<end[j])
    count++;
    if(count>max)
        max = count;
    i++;
- else
    count--;
    j++
- This is O(nlogn) time, O(n) space
- instead of sorting the second array we can have a min heap of the end times 
    
*/
bool compare(const Interval& a , const Interval& b){
    return a.start<b.start;
}
class Solution {

public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), compare);
        priority_queue<int> pq;
        pq.add(intervals[0].end);
        int count = 1;
        int max = 1;
        for(int i = 1;i<intervals.size();i++){
            if(intervals[i] >= pq.peek()){
                count--;
                pq.remove();
            }
            count++;
            if(count>max)
                max = count;
            pq.add(intervals[i].end)
        }
        return max;
    }
};
