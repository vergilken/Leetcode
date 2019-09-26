//
// Created by vergilken on 9/26/19.
//

#ifndef LEETCODE_PROBLEM1197_H
#define LEETCODE_PROBLEM1197_H

class MinimumKnightMoves {
public:
    int minKnightMoves(int x, int y) {
        int maxValue = max(abs(x), abs(y)), minValue = min(abs(x), abs(y));
        int count = 0;
        queue<pair<int, int>> q;
        q.push(source); mp[source.first][source.second] = true;
        while (!q.empty()) {
            auto len = q.size();
            for (size_t trial = 0; trial < len; ++trial) {
                auto pos = q.front();
                q.pop();
                if (pos.first == maxValue && pos.second == minValue) {
                    return count;
                } else {
                    for (size_t i = 0; i < DIRS_X.size(); ++i) {
                        auto temp = make_pair(pos.first + DIRS_X[i], pos.second + DIRS_Y[i]);
                        if (!mp[temp.first][temp.second]) {
                            q.push(temp);
                            mp[temp.first][temp.second] = true;
                        }
                    }
                }
            }
            ++count;
        }

        return count;
    }

private:
    vector<int> DIRS_X = {2,  2,  1, -1};
    vector<int> DIRS_Y = {1, -1,  2, -2};
    pair<int, int> source = {0, 0};
    unordered_map<int, unordered_map<int, bool>> mp;
};
#endif //LEETCODE_PROBLEM1197_H
