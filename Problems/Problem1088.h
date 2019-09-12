//
// Created by vergilken on 9/10/19.
//

#ifndef LEETCODE_PROBLEM1088_H
#define LEETCODE_PROBLEM1088_H

class ConfusingNumber2 {
public:
     int confusing_number_num(int n) {
        for (auto x: {1, 6 ,8, 9}) {
            helper(x, n);
        }
        return count;
    }
private:
    static bool check_confusing_number(int num) {
        vector<char>rot(256, 'x');
        // init function
        rot['0'] = '0', rot['1'] = '1', rot['6'] = '9', rot['8'] = '8', rot['9'] = '6';
        string str = to_string(num), reversedStr;
        for (auto c: str) {
            if (rot[c] == 'x') {
                return false;
            }
            reversedStr += rot[c];
        }
        reverse(begin(reversedStr), end(reversedStr));
        return stoi(reversedStr) == num;
    }

    void helper(long long x, int n) {
        if (x > n) return;
        if (check_confusing_number(x)) ++count;
        for (auto y: elements) {
            helper(x * 10 + y, n);
        }
    }

    const vector<int> elements = {0, 1 ,6 ,8 ,9};
    int count = 0;
};
#endif //LEETCODE_PROBLEM1088_H
