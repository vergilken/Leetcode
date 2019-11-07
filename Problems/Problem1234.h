//
// Created by vergilken on 11/7/19.
//

#ifndef LEETCODE_PROBLEM1234_H
#define LEETCODE_PROBLEM1234_H
class ReplaceTheSubstringForBalancedString {
public:
    static int balanced_string(const string& s) {
        unordered_map<int, int> count;
        int n = s.size(), limit = n / 4, i = 0, res = n;
        for (auto ch : s) {
            ++count[ch];
        }

        for (size_t j = 0; j < s.size(); ++j) {
            --count[s[j]];
            while (i <= n &&
            count['Q'] <= limit && count['W'] <= limit &&
            count['E'] <= limit && count['R'] <= limit) {

            }
        }

        return res;
    }
};
#endif //LEETCODE_PROBLEM1234_H
