// Database = one object that stores many tables and gives access by name.
#pragma once

// table name and column types
#include <string>
// hash map: fast lookup O(1) average by table name
#include <unordered_map>
// Table, Column, Row, Value
#include "Table.h"

// Class Database:
// - public: what other code may call (API).
// - private: inner storage tables_; only methods of Database may touch it.
class Database {
    // callable from outside: create table, get table, check exists
public:
    // add new table with name and schema columns; error if name already used
    void createTable(const std::string& name, const std::vector<Column>& columns);

    // return link to Table so caller can change it (insert rows etc.)
    Table& getTable(const std::string& name);

    // same getTable but when Database is const: read-only link to Table
    const Table& getTable(const std::string& name) const;

    // true if table with this name exists in tables_
    bool hasTable(const std::string& name) const;

    // not visible outside class: direct map access would skip checks
private:
    // dictionary: key = table name (string), value = Table object
    // example: "users" -> users table, "products" -> products table
    std::unordered_map<std::string, Table> tables_;
};
