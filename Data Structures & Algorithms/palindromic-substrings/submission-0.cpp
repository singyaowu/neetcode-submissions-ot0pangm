class Solution {
public:
    int countSubstrings(string s) {
        int ret = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            // odd
            int l = i;
            int r = i;
            while(l >= 0 && l < n && r >= 0 && r < n && s[l] == s[r]) {
                ret++;
                l--;
                r++;
            }
            // even
            l = i;
            r = i+1;
            while(l >= 0 && l < n && r >= 0 && r < n && s[l] == s[r]) {
                ret++;
                l--;
                r++;
            }
        }
        return ret;
    }
};
