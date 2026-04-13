class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<int> s;
        for(int i = 0; i < temperatures.size(); i++) {
            if(s.empty()) {
                s.push(i);
                continue;
            }
            int cur_temp = temperatures[i];
            if(temperatures[s.top()] >= cur_temp) {
                s.push(i);
            } else {
                while (!s.empty() && temperatures[s.top()] < cur_temp) {
                    int prev_idx = s.top();
                    int prev_temp = temperatures[prev_idx];
                    ret[prev_idx] = i - prev_idx;
                    s.pop();
                }
                s.push(i);
            }
        }
        return ret;
    }
};