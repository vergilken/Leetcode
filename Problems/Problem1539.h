//
// Created by Vergilken on 8/17/20.
//

#ifndef LEETCODE_PROBLEM1539_H
#define LEETCODE_PROBLEM1539_H

class KthMissingPossitiveNumber {
public:
    static int find_kth_posstive_missing_number(vector<int>& arr, int k) {
        int maxNum = arr.back() + k + 1;
        arr.push_back(maxNum); arr.insert(arr.begin(), 0);
        for (int i = 1; i < arr.size(); ++i) {
            auto bias = arr[i] - arr[i-1] - 1;
            if (bias > 0) {
                k-= bias;
                if (k <= 0) {
                    return bias + k + arr[i-1];
                }
            }
        }
        return 0;
    }
};
#endif //LEETCODE_PROBLEM1539_H
