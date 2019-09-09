#include "solution.h"

int main() {
    vector<int> nums = {1, 2 ,3};
    auto* obj = new Permutations();
    Printer::print_matrix(obj -> permute(nums));
    return EXIT_SUCCESS;
}