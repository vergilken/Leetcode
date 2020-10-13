//
// Created by Vergilken on 8/23/20.
//

#ifndef LEETCODE_PROBLEM2000_H
#define LEETCODE_PROBLEM2000_H
class ConstructBinaryTreeViaString {
public:
    static TreeNode<int>* construct_binary_tree_via_string(string& str) {
        if (str.empty()) {
            return nullptr;
        }
        size_t start = 0;
        return helper(str, start);
    }

private:
    static TreeNode<int>* helper(string& str, size_t& i) {
        TreeNode<int>* root = nullptr;
        if (i >= str.size()) {
            return root;
        }

        if (str[i] == 'L') {
            return new TreeNode<int>(0);
        } else {
            root = new TreeNode<int>(1);
            if (root -> left == nullptr) {
                root -> left = helper(str, ++i);
            }
            root -> right = helper(str, ++i);

            return root;
        }
    }
};
#endif //LEETCODE_PROBLEM2000_H
