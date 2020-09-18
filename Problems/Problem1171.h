//
// Created by Vergilken on 9/10/20.
//

#ifndef LEETCODE_PROBLEM1171_H
#define LEETCODE_PROBLEM1171_H
class RemZeroSumConsecutiveNodesFromLinkedList {
public:
    static ForwardLinkedListNode<int>* remZeroSumConsSubList(ForwardLinkedListNode<int>* head) {
        vector<int> records;
        vector<int> sum;
        vector<bool> mark;
        while (head != nullptr) {
            records.push_back(head -> value);
            sum.push_back(head -> value + (sum.empty() ? 0 : sum.back()));
            mark.push_back(false);
            auto tmp = head;
            head = head -> next;
            delete tmp;
        }

        size_t right = 0;
        while (right < records.size()) {
            size_t left = 0;
            while (left <= right) {
                auto tmp = sum[right] - sum[left] + records[left];
                if (tmp == 0) {
                    for (auto idx = left; idx <= right; ++idx) {
                        mark[idx] = true;
                    }
                    ++right; break;
                }
                ++left;
            }
            ++right;
        }
        auto dummy = new ForwardLinkedListNode<int>(-1);
        auto result = dummy;
        for (auto idx = 0; idx < mark.size(); ++idx) {
            if (!mark[idx]) {
                auto tmp = new ForwardLinkedListNode<int>(records[idx]);
                dummy -> next = tmp;
                dummy = dummy -> next;
            }
        }
        return result -> next;
    }
};
#endif //LEETCODE_PROBLEM1171_H
