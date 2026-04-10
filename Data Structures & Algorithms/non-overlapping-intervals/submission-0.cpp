class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end());
        auto last = intervals[0];
        int ret = 0;
        for (int i = 1; i < intervals.size(); i++) {
            auto cur = intervals[i];
            if(last[1] > cur[0]) {
                ret++;
                last = cur[1] < last[1]? cur : last;
            } else {
                last = cur;
            }
        }
        return ret;
    }
};
