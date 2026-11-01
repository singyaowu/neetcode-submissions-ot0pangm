class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ret = 0;
        int prev_s = intervals[0][0];
        int prev_e = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            int cur_s = intervals[i][0];
            int cur_e = intervals[i][1];
            if (prev_e <= cur_s) {
                prev_s = cur_s;
                prev_e = cur_e;
            } else {
                ret++;
                if (prev_e > cur_e) {
                    prev_s = cur_s;
                    prev_e = cur_e;
                }
            }
        }
        return ret;
    }
};
