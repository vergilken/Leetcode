//
// Created by Vergilken on 9/10/20.
//

#ifndef LEETCODE_PROBLEM1171_H
#define LEETCODE_PROBLEM1171_H
class RemZeroSumConsecutiveNodesFromLinkedList {
public:
    static ForwardLinkedListNode<int>* remZeroSumConsSubList(ForwardLinkedListNode<int>* head) {
        vector<int> records = {0};
        vector<int> preSum = {0};
        while (head != nullptr) {
            records.push_back(head -> value);
            preSum.push_back(head -> value + preSum.back());
            auto tmp = head;
            head = head -> next;
            delete tmp;
        }
        auto _head = new ForwardLinkedListNode<int>(-1);
        auto dummy = _head;

        int i = 0;
        while (i < records.size()) {
            for (int j = int(records.size()) - 1; j >= i; --j) {
                if (i == j) {
                    auto tmp = new ForwardLinkedListNode<int>(records[i]);
                    _head -> next = tmp;
                    _head = _head -> next;
                    ++i;
                } else if (preSum[i] == preSum[j]) {
                    auto tmp = new ForwardLinkedListNode<int>(records[i]);
                    _head -> next = tmp;
                    _head = _head -> next;
                    i = j + 1;
                }
            }
        }
        return dummy -> next -> next;
    }

    static ForwardLinkedListNode<int>* remZeroSumConsSubListBruteForce(ForwardLinkedListNode<int>* head) {
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
