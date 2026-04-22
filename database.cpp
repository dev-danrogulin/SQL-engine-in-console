// initialize the database in memory

Database db;

// create a table called "users" with the following columns
db.createTable("users", {
    {"id", DataType:Int},
    {"name", DataType:Text},
    {"age", DataType:Int}
});

// inser some data into the "users" table, and print the string representation of the table
Table& users = db.getTable("users");
users.insert({{1, std::string("Alice"), 23}});
users.insert({{2, std::string("Bob"), 17}});
users.insert({{3, std::string("Charlie"), 31}});