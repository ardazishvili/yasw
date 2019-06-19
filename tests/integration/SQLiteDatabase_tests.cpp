#include "../../src/SQLiteColumn.h"
#include "../../src/SQLiteDatabase.h"
#include "../../src/SQLiteTable.h"

#include <array>
#include <cstdio>
#include <gmock/gmock.h>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

using ::testing::_;
using ::testing::Eq;
using ::testing::Return;
using ::testing::StartsWith;

std::string exec(const char* cmd)
{
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
    ASSERT_THROW(openDatabase("/root/db.sqlite34"), std::runtime_error);
}

TEST(Database, throwsExceptionIfAlreadyExistWhenTryToCreate)
{
    ASSERT_THROW(createDatabase("/root/db.sqlite3"), std::runtime_error);
}

TEST(Database, createsTableInEmptyDatabase)
{
    auto id =
        createColumn<int>("id", createConstraint(Constraint::PRIMARY_KEY, Constraint::NOT_NULL));
    auto name = createColumn<std::string>("name", createNoConstraints());
    auto table = createTable("TEST", std::move(id), std::move(name));
    auto db = openDatabase("/root/empty.sqlite3");
    db.createTable(std::move(table));

    ASSERT_THAT(exec("sqlite3 /root/empty.sqlite3 .schema | grep TEST"),
                StartsWith("CREATE TABLE TEST(id INTEGER PRIMARY KEY ,name TEXT);"));
}

class TestObject : public Object
{
public:
    TestObject() = default;
    TestObject(int i, const std::string& str)
        : m_i(i)
        , m_str(str)
    {}

    std::string content() const override
    {
        return std::to_string(m_i) + ", '" + m_str + "'";
    }

private:
    int m_i{1};
    std::string m_str{"first"};
};

TEST(Database, insertsRowIntoEmptyTable)
{
    auto db = openDatabase("/root/tableWithoutRows.sqlite3");
    auto testObject = TestObject();
    db.insert("test", testObject);

    ASSERT_THAT(exec("sqlite3 /root/tableWithoutRows.sqlite3 "
                     "'select * from test' | grep 1"),
                StartsWith("1|first"));
}

TEST(Database, insertSecondRowIntoTableWithOneRow)
{
    auto db = openDatabase("/root/tableWithOneRow.sqlite3");
    auto testObject = TestObject(2, "second");
    db.insert("test", testObject);

    ASSERT_THAT(exec("sqlite3 /root/tableWithOneRow.sqlite3 "
                     "'select * from test' | grep 2"),
                StartsWith("2|second"));
}

TEST(Database, insertTwoRowsIntoEmptyTable)
{
    auto db = openDatabase("/root/tableForInsertionOfMultipleRows.sqlite3");
    auto testObject1 = TestObject();
    db.insert("test", testObject1);
    auto testObject2 = TestObject(2, "second");
    db.insert("test", testObject2);

    ASSERT_THAT(exec("sqlite3 /root/tableForInsertionOfMultipleRows.sqlite3 "
                     "'select * from test' | grep 1"),
                StartsWith("1|first"));
    ASSERT_THAT(exec("sqlite3 /root/tableForInsertionOfMultipleRows.sqlite3 "
                     "'select * from test' | grep 2"),
                StartsWith("2|second"));
}
