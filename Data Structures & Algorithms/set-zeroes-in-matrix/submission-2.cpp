class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int m = matrix.size();
        int n = matrix[0].size();
        bool erase_col0 = false;
        bool erase_row0 = false;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    if (i == 0) {
                        erase_row0 = true;
                    } else {
                        matrix[i][0] = 0;
                    }
                    if (j == 0) {
                        erase_col0 = true;
                    } else {
                        matrix[0][j] = 0;
                    }
                    //cout <<i<<", "<<j<<", erase_col0: " << erase_col0 << ", erase_row0: " << erase_row0 << endl;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        cout << erase_col0 << erase_row0 << endl;
        if (erase_col0) {
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        }
        if (erase_row0) {
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        }
    }
};
