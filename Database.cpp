#include "Database.h"

#include <stdexcept>

// create a new table with the given name and columns
void Database::createTable(const std::string& name, const std::vector<Column>& columns) {
    // if table exists throw runtime error
    if (hasTable(name)) {
        throw std::runtime_error("Table already exists: " + name);
    }

    // add new match "name" -> "Table object"
    tables_.emplace(name, Table(name, columns));
}

// function, return link to Table so called can change it
Table& Database::getTable(const std::string& name) {
    auto it = tables_.find(name);
    if (it == tables_.end()) {
        throw std::runtime_error("Table not found: " + name);
    }

    // return value of the map, second element of the pair
    return it->second;
}

// function, return constant link to Table so called can read it
const Table& Database::getTable(const std::string& name) const {
    auto it = tables_.find(name);
    if (it == tables_.end()) {
        throw std::runtime_error("Table not found: " + name);
    }

    return it->second;
}

bool Database::hasTable(const std::string& name) const {
    return tables_.find(name) != tables_.end();
}