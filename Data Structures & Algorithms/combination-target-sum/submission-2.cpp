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
        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > target)
                return;
            cur.push_back(nums[i]);
            rec_search(nums, target - nums[i], i, ret, cur);
            cur.pop_back();
        }
    }
};
