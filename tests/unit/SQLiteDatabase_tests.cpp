#include "../../src/SQLiteDatabase.h"
#include "mocks/ObjectMock.h"
#include "mocks/SQLInterfaceMock.h"
#include "mocks/TableMock.h"

#include <gmock/gmock.h>

using ::testing::_;
using ::testing::Eq;
using ::testing::Return;

TEST(Database, opensSQLite3DbWhenCreated)
{
    std::unique_ptr<SQLInterfaceMock> interfaceMock = std::make_unique<SQLInterfaceMock>();
    EXPECT_CALL(*interfaceMock, open(_, _, _, _)).Times(1);

    SQLiteDatabase("", std::move(interfaceMock));
}

TEST(Database, throwsExceptionWhenCantOpenDB)
{
    std::unique_ptr<SQLInterfaceMock> interfaceMock = std::make_unique<SQLInterfaceMock>();
    EXPECT_CALL(*interfaceMock, open(_, _, _, _)).WillOnce(Return(1));

    ASSERT_THROW(SQLiteDatabase("", std::move(interfaceMock)), std::runtime_error);
}

TEST(Database, execOnInsert)
{
    std::unique_ptr<SQLInterfaceMock> interfaceMock = std::make_unique<SQLInterfaceMock>();
    EXPECT_CALL(*interfaceMock, open(_, _, _, _)).Times(1);
    EXPECT_CALL(*interfaceMock, exec(_, _, _, _, _)).Times(1);
    auto obj = ObjectMock();
    EXPECT_CALL(obj, content()).Times(1);

    auto db = SQLiteDatabase("", std::move(interfaceMock));
    db.insert("test", obj);
}

TEST(Database, throwsExceptionWhenCantInsert)
{
    std::unique_ptr<SQLInterfaceMock> interfaceMock = std::make_unique<SQLInterfaceMock>();
    EXPECT_CALL(*interfaceMock, open(_, _, _, _)).WillOnce(Return(0));
    EXPECT_CALL(*interfaceMock, exec(_, _, _, _, _)).WillOnce(Return(1));
    auto obj = ObjectMock();
    EXPECT_CALL(obj, content()).Times(1);

    auto db = SQLiteDatabase("", std::move(interfaceMock));
    ASSERT_THROW(db.insert("test", obj), std::runtime_error);
}