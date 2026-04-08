class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int half = n / 2 + (n % 2);
        for (int i = 0; i < half; i++) {
            for (int j = 0; j < n /2; j++) {
                swap(matrix[j][n-1-i], matrix[i][j]);
                swap(matrix[n-1-i][n-1-j], matrix[i][j]);
                swap(matrix[n-1-j][i], matrix[i][j]);
            }
        }

    }
};
