class Solution {
public:
    int numDecodings(string s) {
        int dp2 = 0, dp1 = 1, dp = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0')
                dp = 0;
            else {
                dp += dp1;
                if (i != s.size() - 1 && (s[i] == '1' || (s[i] == '2' && s[i+1] <= '6'))) {
                    dp += dp2;
                }
            }
            dp2 = dp1;
            dp1 = dp;
            dp = 0;
        }
        return dp1;
    }
};
