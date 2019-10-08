//
// Created by vergilken on 10/8/19.
//

#ifndef LEETCODE_PROBLEM1028_H
#define LEETCODE_PROBLEM1028_H

class RecoverTreeFromPreorderTraversal {
private:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;+
        explicit TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    };

public:
    TreeNode* recover_from_preorder(string S) {
        vector<TreeNode*> st;
        for (size_t i = 0, level, val; i < S.size();) {
            for (level = 0; S[i] == '-'; ++i) {
                ++level;
            }

            for (val = 0; i < S.size() && S[i] != '-'; ++i) {
                val = val * 10 + S[i] - '0';
            }

            TreeNode* node = new TreeNode(val);
            while(st.size() > level) {
                st.pop_back();
            }
            if (!st.empty()) {
                if (!(st.back() -> left)) {
                    st.back() -> left = node;
                } else {
                    st.back() -> right = node;
                }
            }

            st.push_back(node);
        }
        return st[0];
    }
};

#endif //LEETCODE_PROBLEM1028_H
