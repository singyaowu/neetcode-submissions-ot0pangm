class Solution {
public:
    int characterReplacement(string s, int k) {
        if (k >= s.size()) return s.size();

        vector<int> cnts(26, 0);
        int n = s.size();
        int l = 0;
        int ret = 0;
        for (int r = 0; r < n; r++) {
            cnts[s[r] - 'A']++;
            int maj = 0;
            for (auto cnt : cnts) {
                maj = max(maj, cnt);
            }
            while (r - l + 1 - maj > k) {
                cnts[s[l] - 'A']--;
                l++;
                maj = 0;
                for (auto cnt : cnts) {
                    maj = max(maj, cnt);
                }
            }
            cout << r-l+1 << endl;
            ret = max(ret, r-l+1);
        }
        return ret;
    }
};
