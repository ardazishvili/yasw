#include <gmock/gmock.h>

#include "../../src/SQLiteDatabase.h"

using ::testing::Eq;
using ::testing::Return;
using ::testing::_;

TEST(Database, throwsExceptionOnWrongFilenameWhenTryToOpen)
{
    ASSERT_THROW(openDatabase("/home/roman/repos/yasw/cmake-build-debug/db.sqlite34"), std::runtime_error);
}

TEST(Database, throwsExceptionIfAlreadyExistWhenTryToCreate)
{
    ASSERT_THROW(createDatabase("/home/roman/repos/yasw/cmake-build-debug/db.sqlite3"), std::runtime_error);
}