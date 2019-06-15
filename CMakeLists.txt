cmake_minimum_required(VERSION 3.13)
project(yasw)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_SOURCE_DIR}/tests")

add_library(yasw
        # interfaces
        src/Column.h
        src/Table.h
        src/Database.h
        src/Constraint.h
        src/SQLInterface.h

        # SQLite3 bindings
        src/SQLiteDatabase.cpp
        src/SQLiteDatabase.h
        src/SQLiteColumn.cpp
        src/SQLiteColumn.h
        src/SQLiteTable.cpp
        src/SQLiteTable.h
        src/SQLiteConstraint.cpp
        src/SQLiteConstraint.h
        src/SQLiteInterface.cpp
        src/SQLiteInterface.h
        src/misc.h)

add_executable(yasw_unit_tests

        # mocks
        tests/unit/mocks/ConstraintMock.h
        tests/unit/mocks/ColumnMock.h
        tests/unit/mocks/SQLInterfaceMock.h
        tests/unit/mocks/TableMock.h

        #tests
        tests/unit/test_main.cpp
        tests/unit/SQLiteColumn_tests.cpp
        tests/unit/SQLiteConstraint_tests.cpp
        tests/unit/SQLiteTable_tests.cpp
        tests/unit/SQLiteDatabase_tests.cpp

        # sources
        src/SQLiteColumn.h
        src/SQLiteColumn.cpp
        src/SQLiteConstraint.cpp
        src/SQLiteConstraint.h
        src/SQLiteTable.h
        src/SQLiteTable.cpp
        src/SQLiteDatabase.h
        src/SQLiteDatabase.cpp
        src/SQLiteInterface.h
        src/SQLiteInterface.cpp
        src/misc.h)
target_link_libraries(yasw_unit_tests gmock gtest sqlite3)

add_executable(yasw_integration_tests
        #tests
        tests/integration/test_main.cpp
        tests/integration/SQLiteDatabase_tests.cpp

        # sources
        src/SQLiteColumn.h
        src/SQLiteColumn.cpp
        src/SQLiteConstraint.cpp
        src/SQLiteConstraint.h
        src/SQLiteTable.h
        src/SQLiteTable.cpp
        src/SQLiteDatabase.h
        src/SQLiteDatabase.cpp
        src/SQLiteInterface.h
        src/SQLiteInterface.cpp
        src/misc.h)
target_link_libraries(yasw_integration_tests gmock gtest sqlite3)
