class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return 0;
        sort(intervals.begin(), intervals.end());
        int last = intervals[0][1];
        int ret = 0;
        for (int i = 1; i < intervals.size(); i++) {
            auto cur = intervals[i];
            if(last > cur[0]) {
                ret++;
                last = min(cur[1], last);
            } else {
                last = cur[1];
            }
        }
        return ret;
    }
};
