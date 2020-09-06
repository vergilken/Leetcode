//
// Created by Vergilken on 9/6/20.
//

#ifndef LEETCODE_PROBLEM0019_H
#define LEETCODE_PROBLEM0019_H

class RemoveNthNodeFromEndOfList {
public:
    ForwardLinkedListNode<int>* remove_nth_node_from_end_of_list(ForwardLinkedListNode<int>* head, int n) {
        auto dummy = new ForwardLinkedListNode<int>(-1);
        dummy -> next = head;

        auto fast = dummy;
        for (int i = 0; i < n; ++i) {
            fast = fast -> next;
        }

        auto slow = dummy;
        while (fast -> next != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }

        auto temp = slow -> next;
        slow -> next = slow -> next -> next;
        delete temp;

        return head;
    }
};
#endif //LEETCODE_PROBLEM0019_H
