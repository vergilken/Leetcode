//
// Created by Vergilken on 9/10/20.
//

#ifndef LEETCODE_PROBLEM1171_H
#define LEETCODE_PROBLEM1171_H
class RemZeroSumConsecutiveNodesFromLinkedList {
public:
    static ForwardLinkedListNode<int>* remZeroSumConsSubList(ForwardLinkedListNode<int>* head) {
        auto it = head;
        vector<int> records;
        while (head != nullptr) {
            records.push_back(head -> value);
            auto tmp = head;
            head = head -> next;
            delete tmp;
        }

        Printer<int> :: print_vector(records);
        return nullptr;
    }
};
#endif //LEETCODE_PROBLEM1171_H
