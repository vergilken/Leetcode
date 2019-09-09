//
// Created by vergilken on 9/8/19.
//

#ifndef ALGORITHMS_PROBLEM0046_H
#define ALGORITHMS_PROBLEM0046_H

class Permutations{
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        helper(permutations, nums, 0);
        return permutations;
    }

private:
    static void helper(vector<vector<int>>& permutations, vector<int>& nums, size_t begin) {
        if (begin == nums.size() - 1) {
            permutations.push_back(nums);
            return;
        } else {
            for (size_t i = begin; i < nums.size(); ++i) {
                swap(nums[i], nums[begin]);
                helper(permutations, nums, begin+1);
                //swap(nums[i], nums[begin]); no need to recover the elements at i and begin
            }
        }
    }
};
#endif //ALGORITHMS_PROBLEM0046_H
