class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() < k)
            return -1;
        return quickSelect(nums, 0, nums.size() - 1, k);
    }
    int quickSelect(vector<int> &nums, int l, int r, int k) {
        int pivot = nums[r];
        int p = l;
        for(int i = l; i < r; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        swap(nums[r], nums[p]);
        if (nums.size() - p == k)
            return nums[p];
        if (nums.size() - p > k) {
            return quickSelect(nums, p+1, r, k);
        }
        return quickSelect(nums, l, p-1, k);
    }
};
