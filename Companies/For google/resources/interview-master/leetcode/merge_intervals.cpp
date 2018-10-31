/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> ans;
        int n = intervals.size();
        if (n == 0) return ans;
        qsort_interval(intervals, 0, n - 1);
        int start = intervals[0].start, end = intervals[0].end;
        for (int i = 0; i < n; ++i) {
            if (intervals[i].start <= end) {
                end = max(intervals[i].end, end);
            }
            else {
                ans.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        ans.push_back(Interval(start, end));
        return ans;
    }
private:
    void qsort_interval(vector<Interval> &intervals, int l, int r) {
        if (l >= r) return;
        int m = (l + r) / 2;
        int x = intervals[m].start;
        swap(intervals[m], intervals[r]);
        int midstart = l;
        for (int i = l; i < r; ++i) {
            if (intervals[i].start < x) {
                swap(intervals[i], intervals[midstart]);
                ++midstart;
            }
        }
        swap(intervals[r], intervals[midstart]);
        qsort_interval(intervals, l, midstart - 1);
        qsort_interval(intervals, midstart + 1, r);
    }
};
