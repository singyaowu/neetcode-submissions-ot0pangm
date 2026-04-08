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
        for (int r = 0; r < n_s; r++) {
            cnts[s[r]]++;
            bool satisfy = true;

            for(auto [c, cnt] : reqs) {
                if(cnts[c] < cnt) {
                    satisfy = false;
                    break;
                }
            }
            while (satisfy) {
                if (ret > r - l + 1) {
                    ret = r - l + 1;
                    min_l = l;
                }
                cnts[s[l]]--;
                l++;
                satisfy = true;
                for(auto [c, cnt] : reqs) {
                    if(cnts[c] < cnt) {
                        satisfy = false;
                        break;
                    }
                }
            }
        }
        return ret < INT_MAX? s.substr(min_l, ret) : "";
    }
};
