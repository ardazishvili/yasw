cmake_minimum_required(VERSION 3.13)
project(yasw)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_SOURCE_DIR}/tests")

add_library(yasw
        src/Database.cpp
        src/Database.h
        src/Column.cpp
        src/Column.h
        src/Table.cpp
        src/Table.h
        src/Constraint.h
        src/SQLiteConstraint.cpp
        src/SQLiteConstraint.h)

add_executable(yasw_unit_tests

        # mocks
        tests/unit/mocks/ConstraintMock.h

        #tests
        tests/unit/test_main.cpp
        tests/unit/SQLiteColumn_tests.cpp
        tests/unit/Constraint_tests.cpp

        # sources
        src/Column.h
        src/Column.cpp
        src/SQLiteConstraint.cpp
        src/SQLiteConstraint.h
        )
target_link_libraries(yasw_unit_tests gmock gtest)