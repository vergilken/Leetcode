//
// Created by Vergilken on 10/10/19.
//

#ifndef LEETCODE_BINARY_TREE_H
#define LEETCODE_BINARY_TREE_H
template <typename T>
class TreeNode{
public:
    T value;
    TreeNode* right;
    explicit TreeNode(T _value) {
        value = _value;
        left = right = nullptr;
    }

    TreeNode* left;
    static TreeNode* generateTree(vector<T>& vec) {
        for (auto val: vec) {
            TreeNode* temp = new TreeNode(val);
        }
    }
};
#endif //LEETCODE_BINARY_TREE_H
