//
// Created by vergilken on 11/4/19.
//

#include "solution.h"

int main() {
    vector<int>vec = {0,0};
    auto head = ForwardLinkedListNode<int> :: generate_forward_list(vec);
    Printer<int> :: print_forward_linked_list(RemZeroSumConsecutiveNodesFromLinkedList :: remZeroSumConsSubList(head));
    return EXIT_SUCCESS;
}