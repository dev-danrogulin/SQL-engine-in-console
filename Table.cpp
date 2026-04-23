#include "Table.h"

// for throw std::runtime_error when row or types invalid
#include <stdexcept>

// for std::holds_alternative on Value (variant)
#include <variant>

// default empty constructor
Table::Table() = default;

// initialize fields with name and columns
Table::Table(const std::string& name, const std::vector<Column>& columns)

    : name_(name), columns_(columns) {
    // rows_ stays empty until insert
}

// method, return link to name, without copy outside
const std::string& Table::getName() const {
    return name_;
}

// method, return link to vector of columns, without copy outside
const std::vector<Column>& Table::getColumns() const {
    return columns_;
}

// method, return constant link to vector of data row
const std::vector<Row>& Table::getRows() const {
    return rows_;
}

// insert a new row into the table
void Table::insert(const Row& row) {

    // check if the number of values in the row matches the number of columns
    if (row.values.size() != columns_.size()) {
        throw std::runtime_error("Row size does not match column count");
    }

    // check type for every value
    for (size_t i = 0; i < row.values.size(); ++i) {
        // value link to the i-element row.values
        const Value& value = row.values[i];

        // type of data, for i-column from scheme
        DataType expectedType = columns_[i].type;

        // column is int but cell is not int inside variant
        if (expectedType == DataType::Int && !std::holds_alternative<int>(value)) {
            throw std::runtime_error("Type mismatch: expected int");
        }
        // column is text but cell is not string inside variant
        if (expectedType == DataType::Text && !std::holds_alternative<std::string>(value)) {
            throw std::runtime_error("Type mismatch: expected text");
        }
    }
    // all cells ok, append one row to storage
    rows_.push_back(row);
}

// method, find index of column by name, return int index
int Table::getColumnIndex(const std::string& columnName) const {
    // linear search in columns_ by name
    for (size_t i = 0; i < columns_.size(); ++i) {
        if (columns_[i].name == columnName) {
            // size_t to int for return type in header
            return static_cast<int>(i);
        }
    }
    throw std::runtime_error("Column not found: " + columnName);
}