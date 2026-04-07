class Solution {
public:
    int rob(vector<int>& nums) {
        //dp_rob[i] = nums[i] + dp_not_rob[i-1];
        // dp_not_rob[i] = max(dp_rob[i-1], dp_not_rob[i-1]);

        int dp_rob = 0;
        int dp_not_rob = 0;
        
        for (int i = 1; i < nums.size() + 1; i++) {
            int dp_not_rob_i_m1 = dp_not_rob;
            int dp_rob_i_m1 = dp_rob;
            dp_rob = nums[i-1] + dp_not_rob_i_m1;
            dp_not_rob = max(dp_rob_i_m1, dp_not_rob_i_m1);
            //cout << dp_rob[i] << ", " << dp_not_rob[i] << endl;
        }
        return max(dp_rob, dp_not_rob);
    }
};
