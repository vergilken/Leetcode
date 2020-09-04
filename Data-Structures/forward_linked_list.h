//
// Created by Vergilken on 8/23/20.
//

#ifndef LEETCODE_FORWARD_LINKED_LIST_H
#define LEETCODE_FORWARD_LINKED_LIST_H
template <typename T>
struct ForwardLinkedListNode{
    T value;
    ForwardLinkedListNode* next;
    explicit ForwardLinkedListNode(T _value) {
        value = _value;
        next = nullptr;
    }
};
#endif //LEETCODE_FORWARD_LINKED_LIST_H
