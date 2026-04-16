class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int i = 0; i < coins.size(); i++) {
            
            vector<int> next_dp(amount+1, 0);
            next_dp[0] = 1;
            for(int a = 1; a <= amount; a++) {
                next_dp[a] = dp[a];
                if (a - coins[i] >= 0) {
                    next_dp[a] += next_dp[a - coins[i]];
                }
            }
            dp = next_dp;
        }
        return dp[amount];
    }
};
