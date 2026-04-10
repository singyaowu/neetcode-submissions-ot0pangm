/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> times;
        for (auto intv: intervals) {
            times.push_back({intv.start, 1});
            times.push_back({intv.end, -1});
        }
        sort(times.begin(), times.end());
        int ret = 0;
        int overlap = 0;
        for (auto [time, cnt] : times) {
            overlap += cnt;
            ret = max(ret, overlap);
        }
        return ret;
    }
};
