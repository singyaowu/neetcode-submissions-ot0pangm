class Solution {
public:

    string encode(vector<string>& strs) {
        string ret = "";
        for (auto s: strs) {
            ret += to_string(s.size()) + "|" + s;
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int offset = 0;
        while (offset < s.size()) {
            int n_start = offset;
            while (s[offset] != '|') {
                offset++;
            }
            int str_len = 
                stoi(s.substr(n_start, offset - n_start));
            ret.push_back(s.substr(offset+1, str_len));
            offset += 1 + str_len;
        }
        return ret;
    }
};
