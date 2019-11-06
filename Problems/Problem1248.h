//
// Created by vergilken on 11/4/19.
//

#ifndef LEETCODE_PROBLEM1248_H
#define LEETCODE_PROBLEM1248_H

class CountNumberOfNiceSubarrays {
public:
    static int number_of_subarrays(vector<int>& nums, int k) {
        at_most_K(nums, k) - at_most_K(nums, k - 1);
    }

private:
    static int at_most_K(vector<int>& nums, int k) {
        int res = 0;
        size_t i = 0;

        for (size_t j = 0; j < nums.size(); ++j) {
            k -= nums[j] % 2;
            while (k < 0) {
                k += nums[i++] % 2;
            }
            res += j - i + 1;
        }

        return res;
    }
};
#endif //LEETCODE_PROBLEM1248_H
