#pragma once

#include <vector>
#include "Value.h"

// One for in the table
// values [0] - by first column, [1] - by second column, etc.
struct Row {
    std::vector<Value> values;
};