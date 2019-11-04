//
// Created by vergilken on 11/4/19.
//

#ifndef LEETCODE_PROBLEM1153_H
#define LEETCODE_PROBLEM1153_H


class StringTransformsIntoAnotherString {
public:
    static bool can_convert(const string& str1, const string& str2) {
        if (str1 == str2) {
            return true;
        }

        unordered_map<char, char> mp;
        for (size_t i = 0; i < str1.size(); ++i) {
            if (mp.find(str1[i]) != mp.end() && mp[str1[i]] != str2[i]) {
                return false;
            }
            mp[str1[i]] = str2[i];
        }

        return set<int>(str2.begin(), str2.end()).size() < 26;
    }
};
#endif //LEETCODE_PROBLEM1153_H
