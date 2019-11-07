#include "./Data-Structures/binary_tree.h"
#include "solution.h"

int main() {
    vector<vector<int>> edges = {
            {0, 1}, {0, 2}, {1, 3},
            {2, 4}, {0, 5}, {3, 6},
            {1, 7}, {6, 8}
    };
    auto temp = new TreeDiameter();
    cout <<  temp -> tree_diameter(edges) << endl;
    return EXIT_SUCCESS;
}