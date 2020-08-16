#include "./Data-Structures/binary_tree.h"
#include "solution.h"

int main() {
    vector<int> result = {1, 2, 3, 4, 5, 6};
    int k = 1;
    cout << FindWinnerOfArrayGame :: getWinner(result, k) <<endl;

    return EXIT_SUCCESS;
}