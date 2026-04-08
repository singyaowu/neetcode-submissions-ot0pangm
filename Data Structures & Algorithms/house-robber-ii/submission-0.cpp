class Solution {
public:
    int rob(vector<int>& nums) {
        int rob_0_1 = nums[0];
        int rob_0_2 = nums[0];
        int n = nums.size();
        int not_rob_0_1 = 0;
        int not_rob_0_2 = 0;

        for (int i = 2; i < n-1; i++) {
            int cur = max(rob_0_2 + nums[i], rob_0_1);
            rob_0_2 = rob_0_1;
            rob_0_1 = cur;
        }
        for (int i = 1; i < n-1; i++) {
            int cur = max(not_rob_0_2 + nums[i], not_rob_0_1);
            not_rob_0_2 = not_rob_0_1;
            not_rob_0_1 = cur;
        }
        return max(max(rob_0_1, not_rob_0_2 + nums[n-1]), not_rob_0_1);
    }
};
