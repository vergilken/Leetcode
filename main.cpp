//
// Created by vergilken on 11/4/19.
//

#include "solution.h"

int main() {
    vector<int>vec = {6, 1, 2, -1, 10, -2, 1, 4, -3,1, -5 , 6};
    auto tmp = ForwardLinkedListNode<int> :: generate_forward_list(vec);
    Printer<int> :: print_forward_linked_list(RemZeroSumConsecutiveNodesFromLinkedList :: remZeroSumConsSubList(tmp));

    vec = {0};
    tmp = ForwardLinkedListNode<int> :: generate_forward_list(vec);
    Printer<int> :: print_forward_linked_list(RemZeroSumConsecutiveNodesFromLinkedList :: remZeroSumConsSubList(tmp));

    return EXIT_SUCCESS;
}