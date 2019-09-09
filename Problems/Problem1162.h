//
// Created by vergilken on 8/26/19.
//

#ifndef ALGORITHMS_PROBLEM1162_H
#define ALGORITHMS_PROBLEM1162_H

class FarLandAsPossible {
private:
    const vector<int> DIRS = {0, 1, 0, -1, 0};
public:
    int maxDistance(vector<vector<int>>& grid) {
        auto m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    visited[i][j] = grid[i][j];
                    q.push(make_pair(i, j));
                }
            }
        }

        int result = -1;
        while (!q.empty()) {
            int length = q.size();
            while (length-- > 0) {
                auto temp = q.front(); q.pop();
                result = max(result, grid[temp.first][temp.second] - 1);
                for (size_t i = 0; i < DIRS.size() - 1; ++i) {
                    int x = temp.first + DIRS[i], y = temp.second + DIRS[i+1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                        visited[x][y] = 1;
                        grid[x][y] = grid[temp.first][temp.second] + 1;
                        q.push(make_pair(x, y));
                    }
                }
            }
        }


        return result == 0 ? -1 : result;
    }
};
#endif //ALGORITHMS_PROBLEM1162_H
