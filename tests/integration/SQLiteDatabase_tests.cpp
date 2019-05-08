#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#include <gmock/gmock.h>

#include "../../src/SQLiteDatabase.h"
#include "../../src/SQLiteTable.h"
#include "../../src/SQLiteColumn.h"

using ::testing::Eq;
using ::testing::StartsWith;
using ::testing::Return;
using ::testing::_;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

TEST(Database, throwsExceptionOnWrongFilenameWhenTryToOpen)
{
    ASSERT_THROW(openDatabase("/home/roman/repos/yasw/cmake-build-debug/db.sqlite34"), std::runtime_error);
}

TEST(Database, throwsExceptionIfAlreadyExistWhenTryToCreate)
{
    ASSERT_THROW(createDatabase("/home/roman/repos/yasw/cmake-build-debug/db.sqlite3"), std::runtime_error);
}

TEST(Database, createsTableInEmptyDatabase)
{
    auto id = createColumn("id", Datatype::INTEGER, createConstraint(true, true));
    auto name = createColumn("name",Datatype::TEXT, createNoConstraints());
    auto table = createTable("TEST", std::move(id), std::move(name));
    auto db = openDatabase("/home/roman/repos/yasw/cmake-build-debug/empty.sqlite3");
    db.createTable(std::move(table));

    ASSERT_THAT(exec("sqlite3 /home/roman/repos/yasw/cmake-build-debug/empty.sqlite3 .schema | grep TEST"),
                StartsWith("CREATE TABLE TEST(id INTEGER PRIMARY KEY ,name TEXT);"));
}