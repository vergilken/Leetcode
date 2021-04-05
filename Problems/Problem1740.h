//
// Created by Vergilken on 4/5/21.
//

#ifndef LEETCODE_PROBLEM1740_H
#define LEETCODE_PROBLEM1740_H
class FindDistanceInBinaryTree {
public:
    static int findDistance(TreeNode<int>* root, int p, int q) {
        TreeNode<int>* ancestor = lowestCommonAncestor(root, p, q);
        if (ancestor == nullptr) {
            return -1;
        } else if (ancestor -> value == p) {
            return findDistanceFromRootToVal(ancestor, q, 0);
        } else if (ancestor -> value  == q) {
            return findDistanceFromRootToVal(ancestor, p, 0);
        } else {
            int pDistance = findDistanceFromRootToVal(ancestor, p, 0);
            int qDistance = findDistanceFromRootToVal(ancestor, q, 0);
            cout<< pDistance << " " << qDistance << endl;
            return pDistance + qDistance;
        }
    }

private:
    static TreeNode<int>* lowestCommonAncestor(TreeNode<int>* root, int p, int q) {
        if (root == nullptr) {
            return nullptr;
        } else if (root -> value == p || root -> value == q) {
            return root;
        }
        TreeNode<int>* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode<int>* right = lowestCommonAncestor(root -> right, p, q);
        return !left ? right : !right ? left : root;
    }

    static int findDistanceFromRootToVal(TreeNode<int>* root, int val, int distance) {
        if (root == nullptr) {
            return 0;
        } else if (root -> value == val) {
            cout << "val: " << val << " distance: " << distance << endl;
            return distance;
        } else {
            return max(findDistanceFromRootToVal(root -> left, val, distance + 1), findDistanceFromRootToVal(root -> right, val, distance + 1));
        }
    }
};
#endif //LEETCODE_PROBLEM1740_H
