//
// Created by vergilken on 11/4/19.
//

#ifndef LEETCODE_PROBLEM1293_H
#define LEETCODE_PROBLEM1293_H

class ShortestPathInGridWithObstaclesElimination {
private:
    vector<int> moves = {1, 0, -1, 0, 1};
    static bool checkBeyondEdge(int xx, int yy, int n, int m) {
        return -1 < xx && xx < n && -1 < yy && yy < m;
    }
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 1 && m == 1) {
            return 0;
        }

        vector<vector<pair<int, int>>> dis (n, vector<pair<int, int>>(m, make_pair(INT_MAX, INT_MAX)));

        queue<pair<int, int>> q;
        q.push({0, 0});
        dis[0][0] = {0, 0};

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            int x = p.first;
            int y = p.second;

            for (int i = 0; i < 4; ++i) {
                int xx = x + moves[i];
                int yy = y + moves[i+1];

                if (checkBeyondEdge(xx, yy, n, m)) {
                    int d = dis[x][y].first + 1;                                    //disatnce
                    int c = dis[x][y].second + (grid[xx][yy] == 1 ? 1 : 0);         //cost
                    if (c <= k && xx == n-1 && yy == m-1) {                         // Found the target
                        return d;
                    } else if (c > k) {
                        continue;
                    } else if (c < dis[xx][yy].second) {                             //A new larger path but cheaper, we have to keep it
                        q.push({xx, yy});
                        dis[xx][yy] = {d, c};
                    }
                }
            }
        }

        return -1;
    }
};
#endif //LEETCODE_PROBLEM1293_H
