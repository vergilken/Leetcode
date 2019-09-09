//
// Created by Vergilken on 8/25/19.
//

#ifndef ALGORITHMS_PROBLEM0304_H
#define ALGORITHMS_PROBLEM0304_H

class NumMatrixImmutable {
public:
    explicit NumMatrixImmutable(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        } else {
            cols = int(matrix[0].size());
            int presums = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix[0].size(); ++j) {
                    vec.push_back(matrix[i][j] + presums);
                    presums = vec.back();
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (vec.empty()) {
            return 0;
        } else {
            int sums = 0;
            for (int row = row1; row < row2 + 1; ++row) {
                int left = rec_to_array_idx(row, col1) - 1 < 0 ? 0 : vec[rec_to_array_idx(row, col1) - 1];
                int right = vec[rec_to_array_idx(row, col2)];
                sums += right - left;
            }
            return sums;
        }
        return 0;
    }

private:
    vector<int> vec;
    int cols;
    int rec_to_array_idx(int row, int col) {
        return row * cols + col;
    }
};
#endif //ALGORITHMS_PROBLEM0304_H
