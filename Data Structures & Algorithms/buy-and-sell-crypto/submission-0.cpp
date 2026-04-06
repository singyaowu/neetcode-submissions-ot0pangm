class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (buy > prices[i]) {
                buy = prices[i];
            }
            else {
                ret = max(ret, prices[i] - buy);
            }
        }
        return ret;
    }
};
