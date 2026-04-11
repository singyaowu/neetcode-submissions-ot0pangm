class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_pos = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (max_pos < i) return false;
            if (max_pos >= nums.size() - 1) return true;
            max_pos = max(max_pos, i + nums[i]);
        }
        return true;
    }
};
