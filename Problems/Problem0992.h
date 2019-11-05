//
// Created by vergilken on 11/5/19.
//

#ifndef LEETCODE_PROBLEM0992_H
#define LEETCODE_PROBLEM0992_H

class SubarraysWithKDifferentIntegers {
public:
    int subarraysWithKDistinct(vector<int>& A, int k) {
        return at_most_K(A, k) - at_most_K(A, k - 1);
    }

private:
    int at_most_K(vector<int>& A, int K) {
        int i = 0, res = 0;
        unordered_map<int, int> count;
        for (size_t j = 0; j < A.size(); ++j) {
            if (!count[A[j]]++) K--;
            while (K < 0) {
                if (!--count[A[i]]) K++;
                i++;
            }

            res += j - i + 1;
        }

        return res;
    }
};
#endif //LEETCODE_PROBLEM0992_H
