//
// Created by vergilken on 9/26/19.
//

#ifndef LEETCODE_PROBLEM1202_H
#define LEETCODE_PROBLEM1202_H

#include "../Utils/utils.h"
class SmallestStringWithSwaps {
public:
    string smallest_string_with_swaps(string s, vector<vector<int>>& pairs) {
        adjList.resize(s.size());
        visited.resize(s.size(), false);
        create_graph(pairs);
        for (size_t i = 0; i < s.size(); ++i) {
            if (!visited[i]) {
                cleanse_mem();
                helper(s, i);
                sort(idxString.begin(), idxString.end());
                sort(indices.begin(), indices.end());
                for (size_t j = 0; j < indices.size(); ++j) {
                    s[indices[j]]=idxString[j];
                }
            }
        }
        return s;
;    }

private:
    vector<int> indices;
    vector<bool> visited;
    vector<vector<int>> adjList;
    string idxString;

    void helper(string &s, int n) {
        visited[n] = true;
        indices.push_back(n);
        idxString += s[n];
        for (size_t i: adjList[n]) {
            if (!visited[i]) {
                helper(s, i);
            }
        }
    }

    void create_graph(const vector<vector<int>>& pairs) {
        for (auto v: pairs) {
            adjList[v[0]].push_back(v[1]);
            adjList[v[1]].push_back(v[0]);
        }
    }

    void cleanse_mem() {
        indices.clear();
        idxString = "";
    }
};
#endif //LEETCODE_PROBLEM1202_H
