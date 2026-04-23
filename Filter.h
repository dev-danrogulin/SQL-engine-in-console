#pragma once

#include "Table.h"
#include <string>
#include <vector>

enum class CompareOp {
    Equal,
    Greater,
    Less
};

struct Condition {
    std::string columnName;
    CompareOp op;
    Value value;
};

std::vector<Row> filterRows(const Table& table, const Condition& condition);