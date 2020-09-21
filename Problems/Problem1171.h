//
// Created by Vergilken on 9/10/20.
//

#ifndef LEETCODE_PROBLEM1171_H
#define LEETCODE_PROBLEM1171_H
class RemZeroSumConsecutiveNodesFromLinkedList {
public:
    static ForwardLinkedListNode<int>* remZeroSumConsSubList(ForwardLinkedListNode<int>* head) {
        vector<int> records;
        while (head != nullptr) {
            records.push_back(head -> value);
            auto tmp = head;
            head = head -> next;
            delete tmp;
        }

        size_t left, right = 0;
        while (right < records.size()) {
            auto sum2right = accumulate(records.begin(), records.begin() + right + 1, 0);
            left = 0;
            while (left <= right) {
                auto sum2left = accumulate(records.begin(), records.begin() + left + 1, 0);
                auto tmp = sum2right - sum2left + records[left];
                if (tmp == 0) {
                    records.erase(records.begin() + left, records.begin() + right + 1);
                    right = 0;
                    break;
                } else {
                    ++left;
                }
            }
            ++right;
        }

        auto dummy = new ForwardLinkedListNode<int>(-1);
        head  = dummy;
        for(int record : records) {
            if (record != 0) {
                auto tmp = new ForwardLinkedListNode<int>(record);
                dummy -> next  = tmp;
                dummy = dummy -> next;
            }

        }

        return head -> next;
    }
};
#endif //LEETCODE_PROBLEM1171_H
