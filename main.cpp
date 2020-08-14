#include "./Data-Structures/binary_tree.h"
#include "solution.h"

int main() {
    vector<vector<int>> temp = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1}
    };
    cout << MinimumSwapsToArrangeBinaryGrid :: minSwaps(temp) << endl;

    return EXIT_SUCCESS;
}