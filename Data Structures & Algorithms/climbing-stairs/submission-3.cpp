class Solution {
public:
    int climbStairs(int n) {
        if (n < 3) return n;
        int dp[2] = {2, 1};
        for (int i = 3; i <= n; i++) {
            dp[i%2] = dp[(i-1)%2] + dp[(i-2)%2];
        }
        return dp[n % 2];
    }
};
