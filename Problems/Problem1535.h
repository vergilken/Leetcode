//
// Created by 冯垦 on 8/16/20.
//

#ifndef LEETCODE_PROBLEM1535_H
#define LEETCODE_PROBLEM1535_H

class FindWinnerOfArrayGame {
public:
    static int getWinner(vector<int>& arr, int k) {
        if (arr.size() < k) {
            int result = INT_MIN;
            for (auto c: arr) {
                result = max(result, c);
            }
            return result;
        } else {
            list<int> record(arr.begin(), arr.end());
            auto pos = record.begin();
            auto next = pos; next++;
            int result = 0, limit = k;
            while (k >0) {
                if (*pos > *next) {
                    result = *pos; --k;
                    record.push_back(*next);
                    auto tmp = next; ++next;
                    record.erase(tmp);
                } else {
                    result = *next;
                    record.push_back(*pos);
                    record.erase(pos);
                    pos = next; next++; k = limit - 1;
                }
            }
            return result;
        }
    }
};
#endif //LEETCODE_PROBLEM1535_H
