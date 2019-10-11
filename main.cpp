#include "./Data-Structures/binary_tree.h"
#include "solution.h"

int main() {
    Node<int>* root = nullptr;
    root = new Node<int>(0);
    root -> left = new Node<int>(1);
    root -> right = new Node<int>(2);
    root -> left -> left = new Node<int>(3);
    Printer<int> :: print_binary_tree(root);
    return EXIT_SUCCESS;
}