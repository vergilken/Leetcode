//
// Created by vergilken on 8/23/19.
//

#ifndef ALGORITHMS_PROBLEM0307_H

#include "../Data-Structures/binary_indexed_tree.h"
class NumArray {
public:
    explicit NumArray(vector<int> nums): nums_(move(nums)), tree_(int(nums_.size())) {
        for (int i = 0; i < int(nums_.size()); ++i) {
            tree_.update(i + 1, nums_[i]);
        }
    }
    ~NumArray() = default;

    void update(int i, int val) {
        tree_.update(i + 1, val - nums_[i]);
        nums_[i] = val;
    }

    int sumRange(int i, int j) {
        return tree_.query(j + 1) - tree_.query(i);
    }

    BinaryIndexedTree* getTree() {
        return &tree_;
    }

private:
    vector<int> nums_;
    BinaryIndexedTree tree_;

};

#define ALGORITHMS_PROBLEM0307_H

#endif //ALGORITHMS_PROBLEM0307_H
