class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> have_coin(n+1, 0);
        vector<int> no_coin(n+2, 0);
        for(int i = n - 1; i >= 0; i--) {
            have_coin[i] = max(no_coin[i+2] + prices[i], have_coin[i+1]);
            no_coin[i] = max(have_coin[i+1] - prices[i], no_coin[i+1]);
        }
        return no_coin[0];
    }
    
    /*dp[n, already_buy/not_buy] = 0
    dp[i, not_buy] = max(dp[i+1, already_buy] - prices[i] , dp[i+1, not_buy])
    dp[i, already_buy] = max(dp[i+1, already_buy], dp[i+2, not_buy] + prices[i])*/

};
