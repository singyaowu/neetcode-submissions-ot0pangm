class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret;
        for(int i = 0; i <= n; i++) {
            int cnt = 0;
            int cur_num = i;
            while(cur_num > 0) {
                cnt++;
                cur_num &= cur_num - 1;
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};
