// now need output into console   
#include "Printer.h"

#include <iostream>
#include <iomanip>

// convert value to string for console output
std::string valueToString(const Value& value) {
    if (std::holds_alternative<int>(value)) {
        return std::to_string(std::get<int>(value));
    }

    return std::get<std::string>(value);
}

void printTable(const Table& table) {
    const auto& columns = table.getColumns();
    const auto& rows = table.getRows();

    // print header
    for (const auto& column : columns) {
        std::cout << std::setw(12) << column.name;
    }
    std::cout << '\n';

    // print separator
    for (size_t i = 0; i < columns.size(); ++i) {
        std::cout << std::setw(12) << "---------";
    }
    std::cout << '\n';

    // print rows
    for (const auto& row : rows) {
        for (const auto& value : row.values) {
            std::cout << std::setw(12) << valueToString(value);
        }
        std::cout << '\n';
    }
}