class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = INT_MIN;
        int ret = INT_MIN;
        for (auto num: nums) {
            if (cur < 0) cur = num;
            else cur += num;
            ret = max(cur, ret);
        }
        return ret;
    }
};
