#include "Database.h"
#include <iostream>
#include "Printer.h"
#include "Filter.h"

void printRows(const Table& table, const std::vector<Row>& rows) {
    const auto& columns = table.getColumns();

    for (const auto& column : columns) {
        std::cout << column.name << '\t';
    }
    std::cout << '\n';

    for (const auto& row : rows) {
        for (const auto& value : row.values) {
            std::cout << valueToString(value) << '\t';
        }
        std::cout << '\n';
    }
}

int main() {
    try {
        Database db;

        // 1. Create Table "users"
        db.createTable("users", {
            {"id", DataType::Int},
            {"name", DataType::Text},
            {"age", DataType::Int}
        });

        // 2. Get table
        Table& users = db.getTable("users");

        // 3. Insert some rows 
        users.insert(
            {
                {1, std::string("Alice"), 23}
            }
        );
        users.insert(
            {
                {2, std::string("Bob"), 27}
            }
        );
        users.insert({
            {3, std::string("Charlie"), 31}
        });

        // 4. Filter rows
        std::cout << "All users:\n";
        printTable(users);

        Condition condition{"age", CompareOp::Greater, 18};
        std::vector<Row> filtered = filterRows(users, condition);

        std:cout << "\nUsers with age > 18:\n";
        printRows(users, filtered);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
} 