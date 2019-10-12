//
// Created by ApolloBoxMacbookPro2 on 10/10/19.
//

#ifndef LEETCODE_SEGMENT_TREE_H
#define LEETCODE_SEGMENT_TREE_H

#include "../Utils/stl_tools.h"

class SegmentTreeNode {
public:
    SegmentTreeNode(int start, int end, int sum,
            SegmentTreeNode* left = nullptr,
            SegmentTreeNode* right = nullptr):
            start(start), end(end), sum(sum), left(left), right(right) {}
    SegmentTreeNode(const SegmentTreeNode&) = delete;
    SegmentTreeNode& operator=(const SegmentTreeNode&) = delete;


public:
    int start;
    int end;
    int sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
};
#endif //LEETCODE_SEGMENT_TREE_H
