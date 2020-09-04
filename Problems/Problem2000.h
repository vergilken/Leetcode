//
// Created by Vergilken on 8/23/20.
//

#ifndef LEETCODE_PROBLEM2000_H
#define LEETCODE_PROBLEM2000_H
class ConstructBinaryTreeViaString {
public:
    static Node<int>* construct_binary_tree_via_string(string& str) {
        if (str.empty()) {
            return nullptr;
        }
        size_t start = 0;
        return helper(str, start);
    }

private:
    static Node<int>* helper(string& str, size_t& i) {
        Node<int>* root = nullptr;
        if (i >= str.size()) {
            return root;
        }

        if (str[i] == 'L') {
            return new Node<int>(0);
        } else {
            root = new Node<int>(1);
            if (root -> left == nullptr) {
                root -> left = helper(str, ++i);
            }
            root -> right = helper(str, ++i);

            return root;
        }
    }
};
#endif //LEETCODE_PROBLEM2000_H
