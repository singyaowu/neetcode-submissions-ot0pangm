class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        auto to_key = [](string s) {
            int cnt[26] = {};
            for (auto c : s) {
                cnt[c-'a']++;
            }
            string ret;
            for (int i = 0; i < 26; i++) {
                ret+= to_string(cnt[i]) + ',';
            }
            return ret;
        };
        unordered_map<std::string, vector<string>> hashmap;
        for(auto str: strs) {
            hashmap[to_key(str)].push_back(str);
        }
        vector<vector<string>> ret;
        for (auto [k, v] : hashmap) {
            ret.push_back(v);
        }
        return ret;
    }
};
