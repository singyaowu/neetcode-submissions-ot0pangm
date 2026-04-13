class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        unordered_map<char, int> s1_map;
        for(auto c: s1) {
            s1_map[c]++;
        }
        unordered_map<char, int> s2_map;
        for (int i = 0; i < s1.size(); i++) {
            s2_map[s2[i]]++;
        }
        int have = 0;
        for(auto [c, cnt] : s1_map) {
            if(s2_map[c] >= cnt) have++;
        }
        if (have == s1_map.size())
            return true;
        for (int i = s1.size(); i < s2.size(); i++) {
            int rm_val = s2[i - s1.size()];
            if (s1_map.count(rm_val) && s2_map[rm_val] == s1_map[rm_val]) {
                have--;
            }
            s2_map[rm_val]--;
            
            int add_val = s2[i];
            s2_map[add_val]++;
            if (s1_map.count(add_val) && s2_map[add_val] == s1_map[add_val]) {
                have++;
            }
            if (have == s1_map.size()) return true;
        }
        return false;
    }
};
