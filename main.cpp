#include "./Data-Structures/binary_tree.h"
#include "solution.h"

int main() {
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 4}};
    auto temp = new TreeDiameter();
    cout << "final result: " <<  temp -> tree_diameter(edges) << endl;
    return EXIT_SUCCESS;
}