//
// Created by vergilken on 8/23/19.
//

#ifndef ALGORITHMS_PROBLEM1157_H

class MajorityChecker {
public:
    explicit MajorityChecker(vector<int>& _arr): a(_arr) {
        srand(time(nullptr));
        for (size_t i = 0; i < _arr.size(); ++i) {
            pos[_arr[i]].push_back(i);
        }
        try_bound = 20;
    }

    int query(int left, int right, int threshold) {
        for (size_t i = 0; i < try_bound; ++i) {
            int elem = a[get_random(left, right)];
            if (get_occurrence(elem, left, right) >= threshold) {
                return elem;
            }
        }
        return -1;
    }

private:
    unordered_map<int, vector<int>> pos;
    vector<int> a;
    int try_bound;

private:
    int get_random(int l , int r) const {
        return rand() % (r - l + 1) + l;
    }

    int get_occurrence(int elem, int left, int right) {
        auto iter = pos.find(elem);
        if (iter == pos.end()) return 0;
        const auto& vec = iter -> second;
        auto iter_l = lower_bound(vec.begin(), vec.end(), left);
        if (iter_l == vec.end()) {
            return 0;
        }

        auto iter_r = upper_bound(vec.begin(), vec.end(), right);
        return iter_r - iter_l;
    }
};

#define ALGORITHMS_PROBLEM1157_H

#endif //ALGORITHMS_PROBLEM1157_H
