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
        vector<int> starts, ends;
        for (auto intv: intervals) {
            starts.push_back(intv.start);
            ends.push_back(intv.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int ret = 0;
        int overlap = 0;

        int s = 0, e = 0;
        while (s < starts.size()) {
            if (ends[e] <= starts[s]) {
                e++;
                overlap--;
            } else {
                s++;
                overlap++;
                ret = max(ret, overlap);
            }
        }
        return ret;
    }
};
