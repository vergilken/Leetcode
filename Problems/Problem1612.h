//
// Created by Vergilken on 10/13/20.
//

#ifndef LEETCODE_PROBLEM1612_H
#define LEETCODE_PROBLEM1612_H

class CheckTwoExpressionTressEquivalent {
public:
    static bool checkEquivalence(TreeNode<char>* root) {
        vector<int> record(26, 0);
        update_map(root, record, 1);
        update_map(root, record, -1);
        int i = 0;
        for (auto num: record) {
            if (num != 0) {
                return false;
            }
        }

        return true;
    }

private:
    static void update_map(TreeNode<char>* root, vector<int>& record, int var) {
        if (root == nullptr) {
            return;
        } else if (root -> value - 'a' >=0 && root -> value - 'a' <= 26) {
            record[root -> value - 'a'] += var;
        }

        update_map(root -> left, record, var);
        update_map(root -> right, record, var);
    }
};
#endif //LEETCODE_PROBLEM1612_H
