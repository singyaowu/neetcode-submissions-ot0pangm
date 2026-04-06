class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left_mut(nums.size(), 1);
        vector<int> right_mut(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++) {
            left_mut[i] = left_mut[i-1] * nums[i-1];
        }
        for(int i = nums.size() - 2; i >= 0; i--) {
            right_mut[i] = right_mut[i+1] * nums[i+1];
        }
        vector<int> ret(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            ret[i] = left_mut[i] * right_mut[i];
        }
        return ret;
    }
};
