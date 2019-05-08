#include <gmock/gmock.h>

#include "../../src/SQLiteDatabase.h"

#include "mocks/TableMock.h"
#include "mocks/SQLInterfaceMock.h"

using ::testing::Eq;
using ::testing::Return;
using ::testing::_;

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