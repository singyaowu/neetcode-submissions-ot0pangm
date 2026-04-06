class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ret = 0;
        int l = 0;
        int r = heights.size() - 1;
        while (l < r) {
            ret = max(ret, (r - l) * min(heights[l], heights[r]));
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ret;
    }
};
