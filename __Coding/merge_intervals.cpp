/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(const Interval a, const Interval b){
        return a.start<b.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if(intervals.size() == 0){
            return ans;
        }
        sort(intervals.begin(),intervals.end(), compare);
        ans.push_back(intervals[0]);
        for(int i = 1; i<intervals.size();i++){
            if(intervals[i].start <= ans.back().end){
                Interval merged(ans.back().start, max(intervals[i].end,ans.back().end));
                ans.pop_back();
                ans.push_back(merged);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};