class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return rec(s, 0, dp);
    }
    int rec(string &s, int start, vector<int> &dp) {
        if (start == s.size()) return 1;
        if (dp[start] != -1) return dp[start];
        int ret = 0;
        if(s[start] != '0') {
            ret += rec(s, start + 1, dp);
            if(start != s.size() - 1 && stoi(s.substr(start, 2)) <= 26) {
                ret += rec(s, start + 2, dp);
            }
        }
        dp[start] = ret;
        return ret;
    }
};
