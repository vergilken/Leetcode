//
// Created by vergilken on 11/5/19.
//

#ifndef LEETCODE_PROBLEM1247_H
#define LEETCODE_PROBLEM1247_H

class MinimumSwapsToMakeStringsEqual {
public:
    static int min_swap(const string& s1, const string& s2) {
        if (s1.size() != s2.size()) {
            return -1;
        }
        int XY = 0, YX = 0;
        for (size_t i = 0; i < s1.size(); ++i) {
            if (s1[i] == 'y' && s2[i] == 'x') {
                ++YX;
            } else if (s1[i] == 'x' && s2[i] == 'y') {
                ++XY;
            }
        }
        if(XY % 2 != YX % 2) return -1;
        return XY / 2 + YX / 2 + (XY % 2) * 2;
    }
};
#endif //LEETCODE_PROBLEM1247_H
