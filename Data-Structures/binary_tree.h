//
// Created by ApolloBoxMacbookPro2 on 10/10/19.
//

#ifndef LEETCODE_BINARY_TREE_H
#define LEETCODE_BINARY_TREE_H
template <typename T>
class Node{
    T value;
    Node* left;
    Node* right;
    explicit Node(T _value) {
        value = _value;
        left = right = nullptr;
    }
};
#endif //LEETCODE_BINARY_TREE_H
