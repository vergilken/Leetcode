//
// Created by Vergilken on 9/20/20.
//

#ifndef LEETCODE_PROBLEM1367_H
#define LEETCODE_PROBLEM1367_H

class LinkedListInBinaryTree {
public:
    static bool is_sub_path(ForwardLinkedListNode<int>* head, Node<int>* root) {
        if (!root) return false;
        if (check_path(head, root)) return true;
        bool left = is_sub_path(head, root -> left);
        bool right = is_sub_path(head, root -> right);
        return left or right;
    }
private:
    static bool check_path(ForwardLinkedListNode<int>* head, Node<int>* root) {
        if (!head) {
            return true;
        } else if (!root && head) {
            return false;
        } else {
            bool flag = head -> value == root -> value;
            bool left = check_path(head -> next, root -> left);
            bool right = check_path(head -> next, root -> right);
            return flag && (left || right);
        }
    }
};
#endif //LEETCODE_PROBLEM1367_H
