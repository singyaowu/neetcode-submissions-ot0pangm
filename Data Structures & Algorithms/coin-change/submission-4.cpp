class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for (int t = 0; t <= amount; t++) {
            if (dp[t] == INT_MAX) continue;
            for(auto coin : coins) {
                if (((long long)coin + t) <= amount && dp[coin + t] > dp[t] + 1) {
                    dp[coin + t] = dp[t] + 1;
                }
            }
        }
        return dp[amount] < INT_MAX? dp[amount] : -1;
    }
};
