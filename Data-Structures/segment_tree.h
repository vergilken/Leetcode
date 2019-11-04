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
    ~SegmentTreeNode() {
        delete left;
        delete right;
        left = right = nullptr;
    }

public:
    int start;
    int end;
    int sum;
    SegmentTreeNode* left;
    SegmentTreeNode* right;
};

class NumArray {
public:
    NumArray(vector<int> nums) {
        nums_.swap(nums);
        if (!nums_.empty()) {
            root_.reset(buildTree(0, nums_.size() - 1));
        }
    }

    void update(int i, int val) {
        updateTree(root_.get(), i, val);
    }

    int sumRange(int i, int j) {
        return sumRange(root_.get(), i, j);
    }

private:
    vector<int> nums_;
    unique_ptr<SegmentTreeNode> root_;

    SegmentTreeNode* buildTree(int start, int end) {
        if (start == end) {
            return new SegmentTreeNode(start, end, nums_[start]);
        }

        int mid = start + (end - start) / 2;
        auto left = buildTree(start, mid);
        auto right = buildTree(mid + 1, end);
        auto node = new SegmentTreeNode(start, end, left -> sum + right -> sum, left, right);
        return node;
    }

    void updateTree(SegmentTreeNode* root, int i, int val) {
        if (root -> start == i && root -> end == i) {
            root -> sum = val;
            return;
        }

        int mid = root -> start + (root -> end - root -> start) / 2;
        if (i <= mid) {
            updateTree(root -> left, i, val);
        } else {
            updateTree(root -> right, i, val);
        }

        root -> sum = root -> left -> sum + root -> right -> sum;
    }

    int sumRange(SegmentTreeNode* root, int i, int j) {
        if (i == root -> sum && j == root -> sum) {
            return root -> sum;
        }

        int mid = root -> start + (root -> end - root -> start ) / 2;
        if (j < mid) {
            return sumRange(root -> left, i, j);
        } else if (i > mid) {
            return sumRange(root -> right, i, j);
        } else {
            return sumRange(root -> left, i, mid) + sumRange(root -> right, mid + 1, j);
        }
    }
};
#endif //LEETCODE_SEGMENT_TREE_H
