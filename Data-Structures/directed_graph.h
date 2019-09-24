//
// Created by vergilken on 9/24/19.
//

#ifndef LEETCODE_DIRECTED_GRAPH_H
#define LEETCODE_DIRECTED_GRAPH_H

#define NIL -1
class DirGraph {
public:
    explicit DirGraph(int _V): V(_V) {
        adj.resize(_V, vector<int>(0));
    };

    // from vertex u to vertex v
    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }

    vector<vector<int>> get_SCC() {
        vector<int> disc(V, NIL), low(V, NIL);
        vector<bool> stackMember(V, false);
        stack<int> st;

        for (auto i = 0; i < V; ++i) {
            if (disc[i] == NIL) {
                SCCUtil(i, disc, low, st, stackMember);
            }
        }

        return components;
    }

private:
    int V;
    vector<vector<int>> adj;
    vector<vector<int>> components;
    void SCCUtil(int u, vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& stackMember) {
        static int time = 0;
        disc[u] = low[u] = ++time;
        st.push(u);
        stackMember[u] = true;

        // Go through all vertices adjacent to vertex u,
        // and update low-link value of its adjacent vertices in stack
        for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
            if (disc[*i] == NIL) {
                SCCUtil(*i, disc, low, st, stackMember);
                low[u] = min(low[u], low[*i]);
            } else if (stackMember[*i]) {
                low[u] = min(low[u], disc[*i]);
            }
        }

        // record elements in the same component from the stack
        // and pop off these elements
        if (low[u] == disc[u]) {
            vector<int> temp = {u};
            stackMember[u] = false;
            while (st.top() != u) {
                auto elem = st.top(); st.pop();
                temp.push_back(elem);
                stackMember[elem] = false;
            }
            // pop vertex u
            st.pop();
            components.push_back(temp);
        }
    }
};
#endif //LEETCODE_DIRECTED_GRAPH_H
