cmake_minimum_required(VERSION 3.13)
project(yasw)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory("${CMAKE_SOURCE_DIR}/tests")

add_library(yasw
        Database.cpp
        Database.h
        Column.cpp
        Column.h
        Table.cpp
        Table.h
        Constraint.h
        SQLiteConstraint.cpp
        SQLiteConstraint.h )

add_executable(yasw_unit_tests

        # mocks
        tests/unit/mocks/ConstraintMock.h

        #tests
        tests/unit/test_main.cpp
        tests/unit/SQLiteColumn_tests.cpp
        tests/unit/Constraint_tests.cpp

        # sources
        Column.h
        Column.cpp
        SQLiteConstraint.cpp
        SQLiteConstraint.h
        )
target_link_libraries(yasw_unit_tests gmock gtest)