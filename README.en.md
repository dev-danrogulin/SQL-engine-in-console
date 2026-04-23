# MiniSQL (Educational C++ Project)

[Русская версия](./README.md)

A small in-memory project that simulates basic table operations: creating tables, inserting rows, filtering data, and printing results to the console.

## 1) What this project is for

This project is built for learning core C++ and basic database ideas:
- how tabular data can be stored in memory;
- how to split logic into classes/modules (`Database`, `Table`, `Filter`, `Printer`);
- how to validate data types on insert;
- how to implement simple query-like filtering.

## 2) Why this project matters

It helps practice:
- `class`, `public/private`, and encapsulation;
- STL containers (`std::vector`, `std::unordered_map`);
- variant-based typed values (`std::variant<int, std::string>`);
- exception handling with `std::runtime_error`;
- interface/implementation separation (`.h` vs `.cpp`).

In short, it is a clean stepping stone before moving to real SQL engines.

## 3) What the project does

Current demo flow:
1. Creates a `users` table with columns:
   - `id` (`Int`)
   - `name` (`Text`)
   - `age` (`Int`)
2. Inserts several rows.
3. Prints all rows.
4. Filters rows using a condition (`age > 18`).
5. Prints filtered rows.

### Main features
- create named tables in `Database`;
- check table existence;
- get table by name;
- insert rows into `Table` with validation:
  - row size must match column count;
  - each cell type must match column type;
- filter rows by column and comparison operator:
  - `Equal`, `Greater`, `Less`;
- print table data to console.

## 4) How it is implemented

### File-level architecture

- `Value.h`  
  Defines core data types:
  - `DataType` (`Int`, `Text`)
  - `Value = std::variant<int, std::string>`
  - `Column` (name + type)

- `Row.h`  
  Represents one table row: `std::vector<Value> values`.

- `Table.h` / `Table.cpp`  
  Table logic:
  - stores table name, column schema, and rows;
  - `insert` validates row shape and value types;
  - `getColumnIndex` resolves a column name to its index.

- `Database.h` / `Database.cpp`  
  Database container:
  - stores tables in `std::unordered_map<std::string, Table>`;
  - provides `createTable`, `getTable`, `hasTable`.

- `Filter.h` / `Filter.cpp`  
  Query/filter logic:
  - `Condition` (column + operation + value);
  - `filterRows` returns rows matching the condition.

- `Printer.h` / `Printer.cpp`  
  Output helpers for converting and printing data.

- `main.cpp`  
  End-to-end usage example.

### Core design ideas

- **Encapsulation**: internal storage (`tables_`, `rows_`) is private.
- **References**: `getTable` returns a reference to an existing table object.
- **Const-correctness**: const overloads provide read-only access where needed.
- **Type safety**: `std::variant` + `std::holds_alternative`/`std::get`.
- **Fail-fast errors**: clear `runtime_error` messages for invalid operations.

## Build and run

### Option 1: g++

```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp Table.cpp Database.cpp Filter.cpp Printer.cpp -o minisql
./minisql
```

### Option 2: CMake

```bash
cmake -S . -B build
cmake --build build
```

## Example output

The program prints:
- full `users` table;
- filtered rows where `age > 18`.
