//
// Created by vergilken on 11/7/19.
//

#ifndef LEETCODE_PROBLEM1244_H
#define LEETCODE_PROBLEM1244_H

class LeaderBoard {
public:
    LeaderBoard() = default;
    void add_score(int playerId, int score) {
        for (auto & player : players) {
            if (playerId == player.first) {
                player.second += score;
                return;
            }
        }
        players.emplace_back(playerId, score);
    }

    int top(int k) {
        priority_queue<int ,vector<int>, greater<>> q;
        for (auto & player : players) {
            if (q.size() < k) {
                q.push(player.second);
            } else if (player.second > q.top()) {
                q.pop(); q.push(player.second);
            }
        }

        int res = 0;
        while (!q.empty()) {
            res += q.top(); q.pop();
        }

        return res;
    }

    void reset(int playerId) {
        for (auto & player : players) {
            if (player.first == playerId) {
                player.second = 0;
            }
        }
    }

private:
    vector<pair<int, int>> players;
};
#endif //LEETCODE_PROBLEM1244_H
