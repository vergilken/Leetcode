//
// Created by Vergilken on 9/3/20.
//

#ifndef LEETCODE_PROBLEM1265_H
#define LEETCODE_PROBLEM1265_H
class ImmutableLinkedList {
private:
    int value_;
    ImmutableLinkedList* next_;
public:
    void printValue() {
        cout << value_;
    }

    ImmutableLinkedList* getNext() {
        return next_;
    }
};

class PrintImmutableLinkedList {
public:
    void print_linked_list__in_reverse(ImmutableLinkedList* head) {
        if (head == nullptr) {
            return;
        }
        print_linked_list__in_reverse(head -> getNext());
        head -> printValue();
    }

};
#endif //LEETCODE_PROBLEM1265_H
