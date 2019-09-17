#include "solution.h"
#include "./Data-Structures/undirected_graph.h"

int main() {
    Graph g1(5);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 0);
    g1.add_edge(1, 3);
    g1.add_edge(1, 4);
    g1.add_edge(1, 6);
    g1.add_edge(3, 5);
    g1.add_edge(4, 5);
    g1.get_bridges();
    return EXIT_SUCCESS;
}