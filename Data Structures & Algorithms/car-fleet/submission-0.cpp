class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (!position.size())
            return 0;
        vector <pair<int, int>> pairs;
        for (int i = 0; i < position.size(); i++) {
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.rbegin(), pairs.rend());
        int ret = 1;
        double prev_time = (double)(target - pairs[0].first) / pairs[0].second;
        for (auto i = 1; i < pairs.size(); i++) {
            auto [pos, sp] = pairs[i];
            double time = (double)(target - pos) / sp;
            if (time > prev_time) {
                ret++;
                prev_time = time;
            }
        }
        return ret;
    }
};
