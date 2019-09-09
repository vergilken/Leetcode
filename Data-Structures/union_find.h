//
// Created by Vergilken on 8/27/19.
//

#ifndef ALGORITHMS_UNION_FIND_H
#define ALGORITHMS_UNION_FIND_H

template <typename T>
class UnionFind {
public:
    explicit UnionFind(vector<T> nums): father_ (move(nums)) {}

    int union_search(int son) {
        if (check_element_exist(son)) {
            return -1;
        } else if (father_[son] == son) {
            return son;
        } else {
            return father_[son] = union_search(father_[son]);
        }
    }

    bool merge(int x, int y) {
        if (check_element_exist(x) && check_element_exist(y)) {
            int rootX = union_search(x), rootY = union_search(y);
            if (rootX == rootY) {
                return false;
            } else {
                father_[rootX] = rootY;
                return true;
            }
        } else {
            return false;
        }
    }
private:
    vector<T> father_;
    bool check_element_exist (int val) {
        return find(father_.begin(), father_.end(), val) != father_.end();
    }
};
#endif //ALGORITHMS_UNION_FIND_H
