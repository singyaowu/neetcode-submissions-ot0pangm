class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        int l = 0;
        int r = 0;
        unordered_set<int> st;
        while (r < s.size()) {
            while (st.count(s[r])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            r++;
            ret = max(ret, r - l);
        }
        return ret;
    }
};
