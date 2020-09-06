//
// Created by Vergilken on 9/4/20.
//

#ifndef LEETCODE_PROBLEM0092_H
#define LEETCODE_PROBLEM0092_H
class ReverseLinkedList2 {
public:
    static ForwardLinkedListNode<int>* reverse_linked_list_between(ForwardLinkedListNode<int>* head, int left, int right) {
        if (left == right) {
            return head;
        }

        auto dummy = new ForwardLinkedListNode<int>(-1);
        dummy -> next = head;

        auto prev = dummy, cur = head;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev -> next;
            cur = cur -> next;
        }

        for (int i = 0; i < right - left; ++i) {
            auto next = cur -> next;
            cur -> next = next -> next;
            next -> next = prev -> next;
            prev -> next = next;
        }

        return dummy -> next;
    }
};
#endif //LEETCODE_PROBLEM0092_H
