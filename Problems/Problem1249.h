//
// Created by vergilken on 11/4/19.
//

#ifndef LEETCODE_PROBLEM1249_H
#define LEETCODE_PROBLEM1249_H

class MinimumRemoveToMakeValidParentheses {
public:
    static string min_remove_to_make_valid(string& s) {
        stack<char> st;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '*';
                }
            }

            while (!st.empty()) {
                s[st.top()] = '*';
                st.pop();
            }

            s.erase(remove(s.begin(), s.end(), "*"), s.end());
            return s;
        }
    }
};
#endif //LEETCODE_PROBLEM1249_H
