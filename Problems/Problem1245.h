//
// Created by Vergilken on 11/5/19.
//

#ifndef ALGORITHMS_PROBLEM1245_H
#define ALGORITHMS_PROBLEM1245_H

class TreeDiameter {
public:
    int tree_diameter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (auto & edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }

        int init = edges[0][0];
        reset_distance();
        int start = helper(mp, init, 0);
        reset_distance(); visited.clear();
        helper(mp, start, 0);
        return distance;
    }

private:
    int helper(unordered_map<int, vector<int>>& mp, int node, int tempDist) {
        vector<int> neighbors = mp[node];
        int result = node;
        for (int neighbor : neighbors) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                result = helper(mp, neighbor, tempDist + 1);
            }
        }
        distance = max(distance, tempDist);
        return result;
    }

    void reset_distance() {
        distance = 0;
    }
    int distance;
    unordered_map<int, bool> visited;
};
#endif //ALGORITHMS_PROBLEM1245_H
