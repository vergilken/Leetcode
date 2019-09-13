//
// Created by vergilken on 9/12/19.
//

#ifndef ALGORITHMS_PROBLEM1186_H
#define ALGORITHMS_PROBLEM1186_H
class MaxSubarraySumWithOneDeletion {
public:
    int maximumSum(vector<int>& arr) {
        int arrSize = arr.size();
        vector<int> maxEndHere(arrSize, 0);
        vector<int> maxStartHere(arrSize, 0);
        int result = arr[0];
        maxEndHere[0] = arr[0];
        for (size_t i = 1; i < arrSize; ++i) {
            maxEndHere[i] = max(maxEndHere[i-1] + arr[i], arr[i]);
            result = max(result, maxEndHere[i]);
        }

        maxStartHere[arrSize-1] = arr[arrSize-1];

        // the value of size_t cannot be self-decreased to -1
        for (int i = arrSize - 2; i >= 0; --i) {
            maxStartHere[i] = max(maxStartHere[i+1] + arr[i], arr[i]);
        }

        for (size_t i = 1; i < arrSize - 1; ++i) {
            result = max(result, maxEndHere[i-1] + maxStartHere[i+1]);
        }

        return result;
    }

private:

};
#endif //ALGORITHMS_PROBLEM1186_H
