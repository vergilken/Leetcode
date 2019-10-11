//
// Created by ApolloBoxMacbookPro2 on 10/10/19.
//

#ifndef LEETCODE_BINARY_TREE_H
#define LEETCODE_BINARY_TREE_H
template <typename T>
struct Node{
    T value;
    Node* right;
    explicit Node(T _value) {
        value = _value;
        left = right = nullptr;
    }

    Node* left;
};
#endif //LEETCODE_BINARY_TREE_H
