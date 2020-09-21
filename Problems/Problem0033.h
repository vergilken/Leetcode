//
// Created by Vergilken on 9/21/20.
//

#ifndef LEETCODE_PROBLEM0033_H
#define LEETCODE_PROBLEM0033_H

class SearchInRotatedSortedArray {
public:
    static size_t search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return -1;
        } else if (nums.size() == 1 && nums.back() != target) {
            return -1;
        }

        size_t leftIdx = 0, rightIdx = nums.size() - 1, mid = 0;
        while (leftIdx + 1 != rightIdx) {
            mid = (leftIdx + rightIdx) >> 1;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[leftIdx] < nums[mid]) {
              if (nums[leftIdx] <= target && target <= nums[mid]) {
                  rightIdx = mid;
              } else {
                  leftIdx = mid;
              }
            } else {
                if (nums[mid] <= target && target <= nums[rightIdx]) {
                    leftIdx = mid;
                } else {
                    rightIdx = mid;
                }
            }
        }
        if (nums[leftIdx] == target) {
            return true;
        } else if (nums[rightIdx] == target) {
            return true;
        } else {
            return false;
        }
    }
};
#endif //LEETCODE_PROBLEM0033_H
