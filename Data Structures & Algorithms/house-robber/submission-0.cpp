class Solution {
public:
    int rob(vector<int>& nums) {
        //dp_rob[i] = nums[i] + dp_not_rob[i-1];
        // dp_not_rob[i] = max(dp_rob[i-1], dp_not_rob[i-1]);

        vector<int> dp_rob(nums.size() + 1, 0);
        vector<int> dp_not_rob(nums.size() + 1, 0);
        
        for (int i = 1; i < nums.size() + 1; i++) {
            dp_rob[i] = nums[i-1] + dp_not_rob[i-1];
            dp_not_rob[i] = max(dp_rob[i-1], dp_not_rob[i-1]);
            //cout << dp_rob[i] << ", " << dp_not_rob[i] << endl;
        }
        return max(dp_rob[nums.size()], dp_not_rob[nums.size()]);
    }
};
