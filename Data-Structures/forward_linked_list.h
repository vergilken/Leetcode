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
public:
    static ForwardLinkedListNode<T>* generate_forward_list(const vector<T> vec) {
        auto idx = new ForwardLinkedListNode<T>(-1);
        auto head = idx;
        for (auto it = vec.begin(); it != vec.end(); it++) {
            auto tmp = new ForwardLinkedListNode<T>(*it);
            idx -> next = tmp;
            idx = tmp;
        }
        return head;
    }
};
#endif //LEETCODE_FORWARD_LINKED_LIST_H
