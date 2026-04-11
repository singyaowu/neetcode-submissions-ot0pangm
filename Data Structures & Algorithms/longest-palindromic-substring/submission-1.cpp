class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = 0;
        int max_i = 0;
        for (int i = 0; i < n; i++) {
            int half = 0;
            while (i-half-1 >= 0 && i+half+1 < n && s[i-half-1] == s[i+half+1]) {
                half++;
            }
            if (maxlen < half * 2 + 1) {
                max_i = i - half;
                maxlen = half * 2 + 1;
            }
            half = 0;
            while (i-half >= 0 && i+1+half < n && s[i-half] == s[i+1+half]) {
                half++;
            }
            if (maxlen < half * 2) {
                max_i = i - half + 1;
                maxlen = half * 2;
            }
        }
        return s.substr(max_i, maxlen);
    }
};
