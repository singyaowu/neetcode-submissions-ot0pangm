class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0;
        while(i < intervals.size() && intervals[i][1] < newInterval[0])
            i++;
        int j = i;

        while (j < intervals.size() && (intervals[j][0] <= newInterval[1] || intervals[j][1] <= newInterval[0])) {
            newInterval[0] = min(intervals[j][0], newInterval[0]);
            newInterval[1] = max(intervals[j][1], newInterval[1]);
            j++;
        }
        // cout << newInterval[0] << newInterval[1] << i << j<< endl;
        if (i < j) {
            intervals[i] = newInterval;
            if (j - i > 1)
                intervals.erase(intervals.begin() + i + 1, intervals.begin() + j);
        } else {
            intervals.insert(intervals.begin() + i, newInterval);
        }
        
        return intervals;
    }
};
