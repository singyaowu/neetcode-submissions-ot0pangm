class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> cur;
        rec_search(nums, target, 0, ret, cur);
        return ret;
    }

    void rec_search(const vector<int> & nums, int target, int idx, vector<vector<int>> &ret, vector<int> &cur) {
        if (target == 0) {
            ret.push_back(cur);
            return;
        }
        if (idx >= nums.size() || target < nums[idx]) {
            return;
        }
        rec_search(nums, target, idx+1, ret, cur);
        int insert_cnt = 0;
        while(target >= nums[idx]) {
            cout << target << " " << idx << endl;
            cur.push_back(nums[idx]);
            target -= nums[idx];
            rec_search(nums, target, idx+1, ret, cur);
            insert_cnt++;
        }
        for (int i = 0; i < insert_cnt; i++) {
            cur.pop_back();
        }
    }
};
