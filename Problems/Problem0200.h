//
// Created by Vergilken on 8/27/19.
//

#ifndef ALGORITHMS_PROBLEM0200_H
#define ALGORITHMS_PROBLEM0200_H

#include "../Utils/utils.h"
class NumberOfIsland {
public:
    explicit NumberOfIsland() = default;
    int num_island(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int n = grid.size(), m = grid[0].size(), numOfIslands = 0;
        fill_n(back_inserter(father_), m * n, -1);
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    father_[i * m + j] = i * m + j; ++numOfIslands;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (size_t k = 0; k < father_.size() - 1; ++k) {
                    if (isIsland(i + DIRS[k], j + DIRS[k+1], n, m) &&
                    merge((i + DIRS[k]) * m + j + DIRS[k+1] , i * m + j)) {
                        --numOfIslands;
                    }
                }
            }
        }

        return numOfIslands;
    }
private:
    int find_union (int x) {
        if (father_[x] == x) return x;
        return father_[x] = find_union (father_[x]);
    }

    bool merge (int x, int y) {
        if (father_[x] == -1 || father_[y] == -1) return false;
        int root_x = find_union (x);
        int root_y = find_union (y);
        if (find_union (root_x) != find_union (root_y)) {
            father_[root_x] = root_y;
            return true;
        }
        else
            return false;
    }

    static inline bool isIsland (int x, int y, int n, int m) {
        return x >=0 && x < n && y >=0 && y < m;
    }

    vector<int> father_;
    const vector<int> DIRS = {0, 1, 0, -1, 0};
};
#endif //ALGORITHMS_PROBLEM0200_H
