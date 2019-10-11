#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

std::set<int> intersection(const std::set<int> &lhs, const std::set<int> &rhs);
std::set<int> sUnion(const std::set<int> &lhs, const std::set<int> &rhs);
std::set<int> difference(const std::set<int> &lhs, const std::set<int> &rhs);
void printSet(const std::set<int> in_set);
