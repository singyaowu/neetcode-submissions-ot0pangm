class Solution {
public:
    string minWindow(string s, string t) {
        int n_s = s.size();
        unordered_map<char, int> reqs;
        for (auto c: t)
            reqs[c]++;

        unordered_map<char, int> cnts;
        int l = 0;
        int ret = INT_MAX;
        int min_l = -1;
        int have = 0;
        for (int r = 0; r < n_s; r++) {
            cnts[s[r]]++;
            
            if (reqs.count(s[r]) && cnts[s[r]] == reqs[s[r]]) {
                have++;
            }
            while (have == reqs.size()) {
                if (ret > r - l + 1) {
                    ret = r - l + 1;
                    min_l = l;
                }
                cnts[s[l]]--;
                if (reqs.count(s[l]) && cnts[s[l]] < reqs[s[l]]) {
                    have--;
                }   
                l++;
            }
        }
        return ret < INT_MAX? s.substr(min_l, ret) : "";
    }
};
