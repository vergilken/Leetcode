//
// Created by Vergilken on 8/23/20.
//

#ifndef LEETCODE_PROBLEM0124_H
#define LEETCODE_PROBLEM0124_H
class BinaryTreeMaximumPathSum {
public:
    static int maxPathSum(TreeNode<int>* root) {
        int result = INT_MIN;
        helper(root, result);
        return result;
    }

private:
    static int helper(TreeNode<int>* root, int& result) {
        if (root == nullptr) {
            return INT_MIN;
        }

        int left = helper(root -> left, result);
        int right = helper(root -> right, result);
        int sum = root -> value;
        if (left >= 0) {
            sum += left;
        }
        if (right >= 0) {
            sum += right;
        }

        result = max(result, sum);
        return max(left, right) > 0 ? root -> value + max(left, right) : root -> value;
    }
};
#endif //LEETCODE_PROBLEM0124_H
