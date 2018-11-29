#pragma once

#include <vector>

// Get change for a given amount of money using minimal number of coins.
std::vector<int> get_change(const std::vector<int> &denominations, int amount);