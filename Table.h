#pragma once

#include <string>
#include <vector>
#include "Value.h"
#include "Row.h"


class Table {
    public:
        // constructor and destructor
        Table();
        // creating table with name and columns
        Table(const std::string& name, const std::vector<Column>& columns);

        // getters for name, columns, and rows
        // get acces for data in table
        const std::string& getName() const;
        const std::vector<Column>& getColumns() const;
        const std::vector<Row>& getRows() const;

        // insert a new row into the table
        void insert(const Row& row);
        // find number of column by name
        int getColumnIndex(const std::string& columnName) const;

    private:
        std::string name_;
        std::vector<Column> columns_;
        std::vector<Row> rows_;
};