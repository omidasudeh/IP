#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
 };
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = intervals.size();
        vector<Interval> ans;
        int start = newInterval.start, end = newInterval.end;
        bool insert = false;
        for (int i = 0; i < n; ++i) {
            if (start >= intervals[i].start && start <= intervals[i].end) {
                start = intervals[i].start;
                end = max(intervals[i].end, end);
            }
            else if (end >= intervals[i].start && end <= intervals[i].end) {
                end = intervals[i].end;
                start = min(intervals[i].start, start);
            }
            else if (start <= intervals[i].start && end >= intervals[i].end) {
            }
            else {
                if (!insert && end < intervals[i].start) {
                    ans.push_back(Interval(start, end));
                    insert = true;
                }
                ans.push_back(intervals[i]);
                
            }
            cout << i << " " << start << " " << end << endl;
        }
        if (!insert) ans.push_back(Interval(start, end));
        return ans;
    }
};
int main() {
    // Start typing your code here...
    cout << "Hello world!" << endl;
    Solution s;
    vector<Interval> intervals;
    intervals.push_back(Interval(0, 2));
    intervals.push_back(Interval(3, 5));
    intervals.push_back(Interval(6, 8));
    intervals.push_back(Interval(10, 12));
    intervals.push_back(Interval(13, 15));
    vector<Interval> ans = s.insert(intervals, Interval(4, 7));
    for (int i = 0; i < ans.size(); ++i) {
	cout << ans[i].start << " , " << ans[i].end << endl;
	}
	return 0;
}
