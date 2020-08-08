#include "./Data-Structures/binary_tree.h"
#include "solution.h"

int main() {
    auto arrayReader = new ArrayReader(vector<int>{0,0,0,1,1});
    cout << GuessMajorityInHiddenArray :: guessMajority(*arrayReader) << endl;
    return EXIT_SUCCESS;
}