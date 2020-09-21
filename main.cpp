//
// Created by vergilken on 11/4/19.
//

#include "solution.h"

int main() {
    vector<int>vec = {2};
    auto tmp = ForwardLinkedListNode<int> :: generate_forward_list(vec);
    NextGreaterNodeInLinkedList :: next_larger_nodes(tmp);

    return EXIT_SUCCESS;
}