class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (auto s : strs) {
            int cnt[26] = {};
            for(auto c : s) {
                cnt[c-'a']++;
            }
            string hash = "";
            for(int i = 0; i < 26; i++) {
                hash += char('a' + i) + to_string(cnt[i]) + ",";
            }
            m[hash].push_back(s);
        }
        vector<vector<string>> ret;
        for (auto [k, v]: m) {
            ret.push_back(v);
        }
        return ret;
    }
};
