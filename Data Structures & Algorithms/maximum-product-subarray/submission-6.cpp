class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_val = 1;
        int min_val = 1;
        int ret = nums[0];
        for (auto num : nums) {
            int prev_max = max_val;
            max_val = max(max(num * max_val, num * min_val), num);
            min_val = min(min(num * prev_max, num * min_val), num);
            ret = max(ret, max_val);
        }
        return ret;

    }
};
