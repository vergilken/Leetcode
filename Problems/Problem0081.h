//
// Created by Vergilken on 9/21/20.
//

#ifndef LEETCODE_PROBLEM0081_H
#define LEETCODE_PROBLEM0081_H

class SearchInRotatedArray2 {
public:
    static int search(const vector<int>& nums, int target) {
        if (nums.size() == 0 || nums.size() == 1 && nums[0] != target) {
            return false;
        }

        size_t left = 0, right = nums.size() - 1;
        while (left + 1 != right) {
            auto mid = (left + right) >> 1;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] > nums[left]) {
                if (nums[left] <= target && target <= nums[mid]) {
                    right = mid;
                } else {
                    left = mid;
                }
            } else if (nums[left] > nums[mid]){
                if (nums[mid] <= target && target <= nums[right]) {
                    left = mid;
                } else {
                    right = mid;
                }
            } else {
                ++left;
            }
        }

        if (nums[left] == target || nums[right] == target) {
            return true;
        } else {
            return false;
        }
    }
};
#endif //LEETCODE_PROBLEM0081_H
