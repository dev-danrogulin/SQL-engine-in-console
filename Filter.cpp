// filter rows by condition
// this file mapping all rows in the table and checking condition for each row

#include "Filter.h"
#include <stdexcept>

static bool compareValue (const Value& left, CompareOp op, const Value& right) {
    // match int or int
    if (std::holds_alternative<int> (left) && std::holds_alternative<int>(right)) {
        int l = std::get<int>(left);
        int r = std::get<int>(right);

        if (op == CompareOp::Equal) return l == r;
        if (op == CompareOp::Greater) return l > r;
        if (op == CompareOp::Less) return l < r;
    }

    // match int or string
    if (std::holds_alternative<std::string>(left) &&
        std::holds_alternative<std::string>(right)) {
            const std::string& l = std::get<std::string>(left);
            const std::string& r = std::get<std::string>(right);

            if (op == CompareOp::Equal) return l == r;
            if (op == CompareOp::Greater) return l > r;
            if (op == CompareOp::Less) return l < r;
        }

        throw std::runtime_error("Cannot compare values of different types");
}

std::vector<Row> filterRows(const Table& table, const Condition& condition) {
    std::vector<Row> result;

    int columnIndex = table.getColumnIndex(condition.columnName);
    const auto& rows = table.getRows();

    for (const auto& row : rows) {
        const Value& cellValue = row.values[columnIndex];

        if (compareValue(cellValue, condition.op, condition.value)) {
            result.push_back(row);
        }
    }

    return result;
}