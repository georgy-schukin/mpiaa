#pragma once

#include <vector>

// Get change for the given amount of money using minimal number of coins of given denominations.
std::vector<int> get_change(const std::vector<int> &denominations, int amount);