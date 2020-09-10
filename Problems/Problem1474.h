//
// Created by Vergilken on 9/6/20.
//

#ifndef LEETCODE_PROBLEM1474_H
#define LEETCODE_PROBLEM1474_H

class DeleteNNodesAftserMNodesOfLinkedList {
public:
    ForwardLinkedListNode<int>* delNodes(ForwardLinkedListNode<int>* head, int m, int n) {
        auto dummy = new ForwardLinkedListNode<int>(-1);
        dummy -> next = head;
        auto fast = dummy, slow = dummy;

        while (fast != nullptr) {
            for (int i = 0; i < m && slow != nullptr; i++) {
                slow = slow -> next;
            }

            fast = slow;
            for (int i = 0; i < n && fast != nullptr; i++) {
                fast = fast -> next;
            }

            if (slow != nullptr) {
                slow -> next = fast ? fast -> next : nullptr;
            }
        }
        return dummy -> next;
    }
};
#endif //LEETCODE_PROBLEM1474_H
