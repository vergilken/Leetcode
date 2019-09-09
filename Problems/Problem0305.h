//
// Created by vergilken on 8/27/19.
//

#ifndef ALGORITHMS_PROBLEM0305_H
#define ALGORITHMS_PROBLEM0305_H

#include "../Utils/utils.h"
class NumOfIsland2 {
public:
    explicit NumOfIsland2() = default;
    vector<int> num_island_2(int n, int m, vector<pair<int, int>>& positions) {
        vector<int> result;
        if (positions.empty()) {
            return result;
        }

        int numOfIslands = 0, cnt = positions.size();
        fill_n(back_inserter(father_), m * n, -1);

        for (auto i = 0; i < cnt; ++i) {
            int position = positions[i].first * m + positions[i].second;
            if (father_[position] == -1) {
                father_[position] = position; ++numOfIslands;
            }

            for (size_t k = 0; k < DIRS.size() - 1; ++k) {
                auto x = positions[i].first + DIRS[k];
                auto y = positions[i].second + DIRS[k+1];
                if (check_edge(x, y, n, m)) {
                    if (merge(position, x * m + y)) {
                        --numOfIslands;
                    }
                }
            }
            result.push_back(numOfIslands);
        }

        return result;
    }

private:
    int union_search(int son) {
        if (father_[son] == son) {
            return son;
        } else {
            return father_[son] = union_search(father_[son]);
        }
    }

    bool merge(int x, int y) {
        if (father_[x] == -1 || father_[y] == -1) {
            return false;
        }
        int rootX = union_search(x), rootY = union_search(y);
        if (rootX == rootY) {
            return false;
        } else {
            father_[rootX] = rootY;
            return true;
        }
    }

    static inline bool check_edge(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    vector<int> father_;
    const vector<int> DIRS = {0, 1, 0, -1, 0};
};
#endif //ALGORITHMS_PROBLEM0305_H
