//
// Created by vergilken on 9/10/19.
//

#ifndef LEETCODE_PROBLEM1088_H
#define LEETCODE_PROBLEM1088_H

class ConfusingNumber2 {
private:
    static bool confusing_number(int num) {
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
};
#endif //LEETCODE_PROBLEM1088_H
