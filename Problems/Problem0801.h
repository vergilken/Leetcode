//
// Created by vergilken on 9/13/19.
//

#ifndef ALGORITHMS_PROBLEM0801_H
#define ALGORITHMS_PROBLEM0801_H

// DP version
class MinSwapsToMakeSequencesIncreasing {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        const size_t n = A.size();
        vector<int> swap(n, INT_MAX);
        vector<int> keep(n, INT_MAX);
         keep[0] = 0;
         swap[0] = 1;
         for (auto i = 1; i < n; ++i) {
             if (A[i-1] < A[i] && B[i-1] < B[i]) {
                 swap[i] = swap[i-1] + 1;
                 keep[i] = keep[i-1];
             }
             if (A[i-1] < B[i] && B[i-1] < A[i]) {
                 swap[i] = min(swap[i], keep[i-1] + 1);
                 keep[i] = min(keep[i], swap[i-1]);
             }
         }

         return min(swap.back(), keep.back());
    }
};

class MinSwapsToMakeSequencesIncreasingMethod2 {
public:
    static int minSwap(vector<int>& A, vector<int>& B) {
        int ans = INT_MAX;
        helper(A, B, 1, 0, ans);
        return ans;
    }

private:
    static void helper(vector<int>& A, vector<int>& B, size_t index, int tempSwapNum, int& ans) {
        if (tempSwapNum >= ans) {
            return;
        } else if (index == A.size()) {
            ans = min(ans, tempSwapNum);
            return;
        } else if (A[index-1] < A[index] && B[index-1] < B[index]) {
            helper(A, B, index + 1, tempSwapNum, ans);
        } else {
            swap(A[index], B[index]);
            helper(A, B, index + 1, tempSwapNum + 1, ans);
            swap(A[index], B[index]);
        }
    }
};
#endif //ALGORITHMS_PROBLEM0801_H
