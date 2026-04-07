class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;
        int dp[2] = {1, 1};
        for (int i = 1; i < n; i++) {
            int cur = dp[i%2];
            dp[(i+1)%2] += cur;
            dp[i%2] = cur;
            cout << dp[0] << dp[1] << endl;
        }
        return dp[n % 2];
    }
};
