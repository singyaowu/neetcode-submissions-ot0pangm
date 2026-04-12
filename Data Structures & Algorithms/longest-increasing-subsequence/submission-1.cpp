class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ret = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            for (int j = i+1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
