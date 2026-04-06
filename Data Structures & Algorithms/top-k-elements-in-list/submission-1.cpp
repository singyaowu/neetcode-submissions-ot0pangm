class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (k == 0) {
            return vector<int>();
        }
        unordered_map<int, int> cnts;
        int max_freq = 0;
        for (auto n: nums) {
            cnts[n]++;
            max_freq = max(cnts[n], max_freq);
        }
        vector<vector<int>> bs(max_freq+1, vector<int>());
        for (auto [k, cnt] : cnts) {
            bs[cnt].push_back(k);
        }
        vector<int> ret;
        for(int i = max_freq; i >= 0; i--) {
            if (bs[i].size() != 0) {
                for (auto key : bs[i]) {
                    ret.push_back(key);
                    if (ret.size() == k) {return ret;}
                }
            }
        }
    }
};
