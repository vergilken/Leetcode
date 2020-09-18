//
// Created by vergilken on 11/4/19.
//

#include "solution.h"

int main() {
    vector<int>vec = {1, 2, 3, -6, 6, -6, 1, -1, 2};
    auto head = ForwardLinkedListNode<int> :: generate_forward_list(vec);
    RemZeroSumConsecutiveNodesFromLinkedList :: remZeroSumConsSubList(head);
    return EXIT_SUCCESS;
}