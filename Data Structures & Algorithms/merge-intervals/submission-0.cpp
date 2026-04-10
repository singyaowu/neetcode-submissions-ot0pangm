class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        for (auto intv : intervals) {
            if (ret.empty() || ret.back()[1] < intv[0])
                ret.push_back(intv);
            else{
                ret.back()[0] = min(intv[0], ret.back()[0]);
                ret.back()[1] = max(intv[1], ret.back()[1]);
            }
        }
        return ret;
    }
};
