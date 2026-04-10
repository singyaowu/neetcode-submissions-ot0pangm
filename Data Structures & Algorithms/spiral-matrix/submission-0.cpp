class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return vector<int>();
        }
        vector<int> ret;
        int top = 0, bottom = matrix.size();
        int left = 0, right = matrix[0].size();
        while (top < bottom && left < right) {
            for (int i = left; i < right; i++) {
                ret.push_back(matrix[top][i]);
            }
            for (int i = top + 1; i < bottom - 1; i++) {
                ret.push_back(matrix[i][right-1]);
            }
            if (bottom - top > 1) {
                for (int i = right-1; i >= left; i--) {
                    ret.push_back(matrix[bottom-1][i]);
                }
            }
            if (right - left > 1) {
                for (int i = bottom-2; i >= top + 1; i--) {
                    ret.push_back(matrix[i][left]);
                }
            }
            printf("lft: %d, right: %d, top: %d, bottom: %d\n", left, right, top, bottom);
            top++, bottom--, left++, right--;
        }
        return ret;
    }
};
