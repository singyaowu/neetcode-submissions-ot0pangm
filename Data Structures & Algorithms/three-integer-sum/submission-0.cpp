class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> rets;
        for (int i = 0; i < nums.size(); i++) {
            int tar = -nums[i];
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k) {
                if (nums[j] + nums[k] > tar) {
                    k--;
                } else if (nums[j] + nums[k] < tar) {
                    j++;
                } else {
                    rets.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                    while(nums[k] == nums[k+1]) k--;
                    while(nums[j] == nums[j-1]) j++;
                }
            }
            while(nums[i] == nums[i+1]) i++;
        }
        return rets;
    }
};
