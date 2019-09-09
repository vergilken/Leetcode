//
// Created by vergilken on 8/23/19.
//

#ifndef ALGORITHMS_BINARY_INDEXED_TREE_H
#define ALGORITHMS_BINARY_INDEXED_TREE_H

class BinaryIndexedTree {
public:
    explicit BinaryIndexedTree(int _length): sums_(_length + 1, 0) {}
    ~BinaryIndexedTree() = default;

    void update(int i , int delta) {
        while (i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) const {
        int sum = 0;
        while (i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:
    vector<int> sums_;
    static inline int lowbit(int num) {
        return num & (-num);
    }
};
#endif //ALGORITHMS_BINARY_INDEXED_TREE_H
