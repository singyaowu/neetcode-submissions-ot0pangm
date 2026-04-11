class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int maxval = INT_MIN;
        int minval = INT_MAX;
        int ret = INT_MIN;
        for (auto num : nums) {
            if (num == 0) {
                maxval = 0;
                minval = INT_MAX;
            } else if (num > 0) {
                maxval = maxval <= 0? num : maxval * num;
                minval = minval == INT_MAX? INT_MAX : minval * num;
            } else {
                int prev_max = maxval;
                maxval = minval == INT_MAX? INT_MIN : minval * num;
                minval = prev_max == INT_MIN? num : prev_max * num;
            }
            ret = max(ret, maxval);
        }
        return ret;

    }
};
