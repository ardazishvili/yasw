cmake_minimum_required(VERSION 3.13)
project(yasw)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_SOURCE_DIR}/tests")

add_library(yasw
        src/Column.h
        src/Table.h
        src/Database.h
        src/Constraint.h
        src/SQLiteDatabase.cpp
        src/SQLiteDatabase.h
        src/SQLiteColumn.cpp
        src/SQLiteColumn.h
        src/SQLiteTable.cpp
        src/SQLiteTable.h
        src/SQLiteConstraint.cpp
        src/SQLiteConstraint.h
        )

add_executable(yasw_unit_tests

        # mocks
        tests/unit/mocks/ConstraintMock.h

        #tests
        tests/unit/test_main.cpp
        tests/unit/SQLiteColumn_tests.cpp
        tests/unit/SQLiteConstraint_tests.cpp

        # sources
        src/SQLiteColumn.h
        src/SQLiteColumn.cpp
        src/SQLiteConstraint.cpp
        src/SQLiteConstraint.h
        )
target_link_libraries(yasw_unit_tests gmock gtest)