//
// Created by Vergilken on 8/23/20.
//

#ifndef LEETCODE_PROBLEM0142_H
#define LEETCODE_PROBLEM0142_H

class LinkedListCycle2 {
public:
    static ForwardLinkedListNode<int>* cycle_entry(ForwardLinkedListNode<int>* head) {
        if (!check_forward_linked_list_cycle(head)) {
            return nullptr;
        } else {
            auto slow = head, fast = head;
            while (fast != nullptr && fast -> next != nullptr) {
                slow = slow -> next;
                fast = fast -> next -> next;
                if (slow == fast) {
                    auto entry = head;
                    while (entry != slow) {
                        entry = entry -> next;
                        slow = slow -> next;
                    }
                    return entry;
                }
            }
            return nullptr;
        }
    }

private:
    static bool check_forward_linked_list_cycle(ForwardLinkedListNode<int>* head) {
        auto slow = head, fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};
#endif //LEETCODE_PROBLEM0142_H
