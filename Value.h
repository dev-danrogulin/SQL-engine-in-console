// compile only once
#pragma once

#include <string>
#include <variant>

// column type: int or text
enum class DataType {
    Int, 
    Text
};

// Value for one cell
// int or string
using Value = std::variant<int, std::string>;

// Description for one column int the table
struct Column {
    std::string name;
    DataType type;
};