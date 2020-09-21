//
// Created by Vergilken on 9/20/20.
//

#ifndef LEETCODE_PROBLEM1091_H
#define LEETCODE_PROBLEM1091_H
class NextGreaterNodeInLinkedList {
public:
    static vector<int> next_larger_nodes(ForwardLinkedListNode<int>* head) {
        stack<int> indexes, tmp;
        vector<int> result;
        int idx = 0;
        while (head != nullptr) {
            result.push_back(0);
            if (tmp.empty() || tmp.top() >= head -> value) {
                tmp.push(head -> value); indexes.push(idx);
            } else {
                while (!tmp.empty() && tmp.top() < head -> value) {
                    result[indexes.top()] = head -> value;
                    tmp.pop(); indexes.pop();
                }
                tmp.push(head -> value); indexes.push(idx);
            }
            head = head -> next; ++idx;
        }
        return result;
    }
};
#endif //LEETCODE_PROBLEM1091_H
