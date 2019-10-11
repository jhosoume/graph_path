#include "helper.hpp"

// Defines helper functions to deal with sets, for this, stl (C++) functions are used

std::set<int> intersection(const std::set<int> &lhs, const std::set<int> &rhs) {
    std::set<int> result;
    std::set_intersection(lhs.begin(), lhs.end(),
                          rhs.begin(), rhs.end(),
                          std::inserter(result, result.end())
                      );
    return result;
}

std::set<int> sUnion(const std::set<int> &lhs, const std::set<int> &rhs) {
    std::set<int> result;
    std::set_union(lhs.begin(), lhs.end(),
                          rhs.begin(), rhs.end(),
                          std::inserter(result, result.end())
                      );
    return result;
}

std::set<int> difference(const std::set<int> &lhs, const std::set<int> &rhs) {
    std::set<int> result;
    std::set_difference(lhs.begin(), lhs.end(),
                          rhs.begin(), rhs.end(),
                          std::inserter(result, result.end())
                      );
    return result;
}

void printSet(const std::set<int> in_set) {
    std::cout << "Printing Set " << std::endl;
    for (int num : in_set) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;
}
