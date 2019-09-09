//
// Created by vergilken on 9/8/19.
//

#ifndef ALGORITHMS_PROBLEM1124_H
#define ALGORITHMS_PROBLEM1124_H

class LongestWellPerformingInterval {
public:
    int longestWPI(vector<int>& hours) {
        size_t n = hours.size();
        int start = 1, dist = INT_MIN;
        vector<int> prefix(n + 1, 0), best(n + 1, INT_MIN);
        for (auto &x: hours) {
            x = (x > 8) ? 1 : -1;
        }
        for (size_t i = 1; i < n + 1; ++i) {
            prefix[i] = prefix[i-1] + hours[i-1];
        }
        best[n] = prefix[n];
        for (size_t i = n-1; i > -1; --i) {
            best[i] = max(best[i+1], prefix[i]);
        }
        for (size_t i = 1; i < n + 1; ++i) {
            if (prefix[start-1] < best[i]) {
                dist = max(dist, int(i - start + 1));
            } else {
                ++start;
            }
        }
        return dist == INT_MIN ? 0: dist;
    }
};
#endif //ALGORITHMS_PROBLEM1124_H
