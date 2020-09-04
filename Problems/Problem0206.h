//
// Created by Vergilken on 9/3/20.
//

#ifndef LEETCODE_PROBLEM0206_H
#define LEETCODE_PROBLEM0206_H
class ReverseLinkedList {
public:
    ForwardLinkedListNode<int>* reverse_linked_list(ForwardLinkedListNode<int>* head) {
        ForwardLinkedListNode<int>* prev = nullptr;
        while (head != nullptr) {
            auto temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }

        return prev;
    }
};
#endif //LEETCODE_PROBLEM0206_H
