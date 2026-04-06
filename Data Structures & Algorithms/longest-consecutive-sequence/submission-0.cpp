class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (auto n: nums) st.insert(n);
        int ret = 0;
        for (auto n: st) {
            if (st.count(n-1) == 0) {
                int len = 1;
                while (st.count(n+1)) {
                    n++;
                    len++;
                }
                ret = max(ret, len);
            }
        }
        return ret;
    }
};
