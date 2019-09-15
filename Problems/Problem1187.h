//
// Created by vergilken on 9/13/19.
//

#ifndef ALGORITHMS_PROBLEM1187_H
#define ALGORITHMS_PROBLEM1187_H

class MakeArrayStrictlyIncreasing {
private:
    static constexpr int _ARRAY_SIZE_ = 2000;
    static constexpr int _ELEMENT_LIMIT_ = 1e9;
public:
    // swap[i][j] := min cost to make a[0~i] valid by a[i] = b[j]
    // keep[i] := min cost to make a[0~i] valid by keeping a[i]
    // swap[0][*] := 1, keep[0] = 0
    // case 1: a[i] > a[i-1], keep[i] = keep[i-1]
    // case 2: b[j] > a[i-1], swap[i][j] = keep[i-1] + 1
    // case 3: a[i] > b[j], keep[i] = min(swap[i-1][k]), k <= j
    // case 4: b[j] > b[k], always true when k < j, swap[i][j] = min(swap[i-1][k] + 1)
    // Ans: min(min(swap[m-1], keep[m-1]))
    int make_array_increasing(vector<int>& arr1, vector<int>& arr2) {
        size_t m = arr1.size();
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(begin(arr2), end(arr2)) - begin(arr2));
        size_t n = arr2.size();

        vector<int> keep(m, _ELEMENT_LIMIT_);
        keep[0] = 0;

        vector<vector<int>> swap(m, vector<int>(n, _ELEMENT_LIMIT_));
        fill(begin(swap[0]), end(swap[0]), 1);

        for (size_t i = 1; i < m; ++i) {
            int minKeep = _ELEMENT_LIMIT_, minSwap = minKeep;
            for (size_t j = 0; j < n; ++j) {
                if (arr1[i] > arr1[i-1]) keep[i] = keep[i-1];
                if (arr2[j] > arr1[i-1]) swap[i][j] = keep[i-1] + 1;
                if (arr1[i] > arr2[j]) minKeep = min(minKeep, swap[i-1][j]);
                if (j > 0) minSwap = min(minSwap, swap[i-1][j-1] + 1);
                keep[i] = min(keep[i], minKeep);
                swap[i][j] = min(swap[i][j], minSwap);
            }
        }

        int minSwap = *min_element(begin(swap.back()), end(swap.back())),
        minKeep = keep.back();
        int ans = min(minSwap, minKeep);
        return ans >= _ELEMENT_LIMIT_ ? -1: ans;
    }
};
#endif //ALGORITHMS_PROBLEM1187_H
