// Given a collection of intervals, merge all overlapping intervals.

// For example,
// Given [1,3],[2,6],[8,10],[15,18],
// return [1,6],[8,10],[15,18].

bool compare(const Interval &a, const Interval &b) {
        return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        if (intervals.empty())
            return ret;
        sort(intervals.begin(), intervals.end(), compare);

        ret.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // compare current interval and the recent merged one.
            if (ret.back().end >= intervals[i].start) {
                ret.back().end = max(ret.back().end, intervals[i].end);
            } else {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};
