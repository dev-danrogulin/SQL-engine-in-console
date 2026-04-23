#include "Database.h"
#include <iostream>
#include "Printer.h"

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

        // 4. Print table
        printTable(users);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
} 