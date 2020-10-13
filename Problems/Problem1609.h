//
// Created by Vergilken on 10/12/20.
//

#ifndef LEETCODE_PROBLEM1609_H
#define LEETCODE_PROBLEM1609_H

class EvenOddTree {
public:
    static bool is_even_odd_tree (TreeNode<int>* root) {
        queue<TreeNode<int>*> q;
        q.push(root);
        int level = -1;
        while (!q.empty()) {
            ++level;
            int val = 0;
            int qsize = q.size(), preValue = 0;
            for (int i = 0; i < qsize; ++i) {
                auto node = q.front(); q.pop();
                if (node -> value % 2 == level % 2) {
                    return false;
                } else if (preValue != 0 &&
                           (preValue >= node -> value && (level % 2 == 0)
                            || (preValue <= node -> value && (level % 2 == 1)))) {
                    return false;
                }
                preValue = node -> value;
                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
        }
        return true;
    }
};
#endif //LEETCODE_PROBLEM1609_H
