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
            top++;
            for (int i = top; i < bottom; i++) {
                ret.push_back(matrix[i][right-1]);
            }
            right--;
            if (!(top < bottom && left < right)) break;
            for (int i = right-1; i >= left; i--) {
                ret.push_back(matrix[bottom-1][i]);
            }
            bottom--;
            for (int i = bottom-1; i >= top; i--) {
                ret.push_back(matrix[i][left]);
            }
            left++;
        }
        return ret;
    }
};
