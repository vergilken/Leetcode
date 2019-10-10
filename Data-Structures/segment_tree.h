//
// Created by ApolloBoxMacbookPro2 on 10/10/19.
//

#ifndef LEETCODE_SEGMENT_TREE_H
#define LEETCODE_SEGMENT_TREE_H

#include "../Utils/stl_tools.h"
struct SegmentTreeNode {
    int start_;
    int end_;
    int sum_;
    SegmentTreeNode* left_;
    SegmentTreeNode* right_;
    explicit SegmentTreeNode(int _start, int _end, int _sum, SegmentTreeNode* _left, SegmentTreeNode* _right) {
        start_ = _start, end_ = _end, sum_ = _sum;
        left_ = _left, right_ = _right;
    }
};

class SegmentTree {
public:
    SegmentTreeNode* build_tree(int start, int end, vector<int>& values) {
        if (start == end) {
            return new SegmentTreeNode(start, end, values[start], nullptr, nullptr);
        }

        int mid = (start + end) / 2;
        auto left = build_tree(start, mid, values);
        auto right = build_tree(mid + 1, end, values);
        return new SegmentTreeNode(start, end, left -> sum_ + right -> sum_, left, right);
    }
};
#endif //LEETCODE_SEGMENT_TREE_H
