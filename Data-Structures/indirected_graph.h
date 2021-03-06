//
// Created by vergilken on 9/16/19.
//

#ifndef ALGORITHMS_INDIRECTED_GRAPH_H
#define ALGORITHMS_INDIRECTED_GRAPH_H

#define NIL -1
class Graph {
public:
    explicit Graph(size_t _V): V(_V) {
        adj.resize(_V, vector<int>(0));
    }
    void add_edge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
    vector<vector<int>> get_bridges() {
        vector<bool> visited(V, false);
        vector<int> disc(V, 0), low(V, 0), parent(V, NIL);

        for (size_t i = 0; i < V; ++i) {
            if (!visited[i]) {
                bridge_util(i, visited, disc, low, parent);
            }
        }
        return bridges;
    }

private:
    int V;
    int curIndex = 0;
    vector<vector<int>> adj;
    vector<vector<int>> bridges;

    void bridge_util(int index, vector<bool>& visited, vector<int>& disc,
                     vector<int>& low, vector<int>& parent) {
        visited[index] = true;
        disc[index] = low[index] = ++curIndex;
        for (auto i = adj[index].begin(); i != adj[index].end(); ++i) {
            auto endPoint = *i;
            if (!visited[endPoint]) {
                parent[endPoint] = index;
                bridge_util(endPoint, visited, disc, low, parent);
                low[index] = min(low[index], low[endPoint]);
                if (low[endPoint] > disc[index]) {
                    bridges.push_back(vector<int>{index, endPoint});
                }
            } else if (endPoint != parent[index]) {
                low[index] = min(low[index], disc[endPoint]);
            }
        }
    }
};
#endif //ALGORITHMS_INDIRECTED_GRAPH_H
