//
// Created by vergilken on 9/15/19.
//

#ifndef ALGORITHMS_PROBLEM1192_H
#define ALGORITHMS_PROBLEM1192_H

#include "../Data-Structures/indirected_graph.h"

class CriticalConnInNetwork {
public:
    vector<vector<int>> critical_connections(int n, vector<vector<int>>& connections) {
        Graph* g1 = new Graph(n + 1);
        for (auto edge: connections) {
            g1 -> add_edge(edge[0], edge[1]);
        }
        return g1 -> get_bridges();
    }
};
#endif //ALGORITHMS_PROBLEM1192_H
