// create object, who will store tables and manage them
#pragma once

#include <string>
#include <unordered_map>
#include "Table.h"

// new dictionary, key = name of table, value = table object
// exemple "users" -> table object, "products" -> table products
class Database {
    public: 
        void createTable(const std::string& name, const std::vector<Column>& columns);
        Table& getTable(const std::string& name);
        const Table& getTable(const std::string& name) const;
        bool hasTable(const std::string& name) const;

    private:
        std::unordered_map<std::string, Table> tables_;
};