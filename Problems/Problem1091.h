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
            cout << head -> value << " ";
            if (tmp.empty() || tmp.top() > head -> value) {
                tmp.push(head -> value); indexes.push(idx);
            }
            result.push_back(head -> value);
            head = head -> next; ++idx;
        }



        Printer<int> :: print_stack(tmp);
        return result;
    }
};
#endif //LEETCODE_PROBLEM1091_H
