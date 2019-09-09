//
// Created by vergilken on 8/23/19.
//

#ifndef ALGORITHMS_PROBLEM0308_H

#include "../Data-Structures/binary_indexed_tree.h"
class NumMatrix {
public:
    explicit NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return;
        } else {
            cols = int(matrix[0].size());
            int preSums = 0;
            for (int i = 0; i < matrix.size(); ++i) {
                for (int j = 0; j < matrix[0].size(); ++j) {
                    vec.push_back(matrix[i][j] + preSums);
                    preSums = vec.back();
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
#define ALGORITHMS_PROBLEM0308_H

#endif //ALGORITHMS_PROBLEM0308_H
