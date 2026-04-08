class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int n = nums.size();

        int rob_0_1 = 0;
        int rob_0_2 = 0;
        int not_rob_0_1 = 0;
        int not_rob_0_2 = 0;

        for (int i = 0; i < n-1; i++) {
            int cur = max(rob_0_2 + nums[i], rob_0_1);
            rob_0_2 = rob_0_1;
            rob_0_1 = cur;
        }
        cout << rob_0_1;
        for (int i = 1; i < n; i++) {
            int cur = max(not_rob_0_2 + nums[i], not_rob_0_1);
            not_rob_0_2 = not_rob_0_1;
            not_rob_0_1 = cur;
        }
        return max(rob_0_1, not_rob_0_1);
    }
};
