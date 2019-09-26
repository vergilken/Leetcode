//
// Created by vergilken on 9/26/19.
//

#ifndef LEETCODE_PROBLEM1200_H
#define LEETCODE_PROBLEM1200_H

class MinimumAbsoluteDifference {
public:
    vector<vector<int>> minimum_absolute_difference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> result;
        int minDiff = INT_MAX;
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            minDiff = min(minDiff, arr[i+1] - arr[i]);
        }
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            if (arr[i+1] - arr[i] == minDiff) {
                result.push_back({arr[i], arr[i+1]});
            }
        }

        return result;
    }
};
#endif //LEETCODE_PROBLEM1200_H
