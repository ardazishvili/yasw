#include <gmock/gmock.h>

#include "../../src/SQLiteTable.h"

#include "mocks/ColumnMock.h"

using ::testing::Eq;
using ::testing::Return;

TEST(Table, consistingOfOneColumnReturnsCorrectString)
{
    std::unique_ptr<ColumnMock> columnMock { std::make_unique<ColumnMock>() };
    EXPECT_CALL(*columnMock, toString()).WillOnce(Return("NAME INT PRIMARY KEY"));
    Columns columns{};
    columns.emplace_back(std::move(columnMock));
    auto table = SQLiteTable("COMPANY", std::move(columns));

    EXPECT_THAT(table.toString(), Eq("CREATE TABLE COMPANY(NAME INT PRIMARY KEY);"));
}

TEST(Table, consistingOfManyColumnsReturnsCorrectString)
{
    std::unique_ptr<ColumnMock> firstColumnMock { std::make_unique<ColumnMock>() };
    EXPECT_CALL(*firstColumnMock, toString()).WillOnce(Return("NAME1 INT PRIMARY KEY"));
    std::unique_ptr<ColumnMock> secondColumnMock { std::make_unique<ColumnMock>() };
    EXPECT_CALL(*secondColumnMock, toString()).WillOnce(Return("NAME2 TEXT NOT NULL"));
    std::unique_ptr<ColumnMock> thirdColumnMock { std::make_unique<ColumnMock>() };
    EXPECT_CALL(*thirdColumnMock, toString()).WillOnce(Return("NAME3 BLOB"));
    Columns columns;
    columns.emplace_back(std::move(firstColumnMock));
    columns.emplace_back(std::move(secondColumnMock));
    columns.emplace_back(std::move(thirdColumnMock));
    auto table = SQLiteTable("COMPANY", std::move(columns));

    EXPECT_THAT(table.toString(), Eq("CREATE TABLE COMPANY(NAME1 INT PRIMARY KEY,"
                                                          "NAME2 TEXT NOT NULL,"
                                                          "NAME3 BLOB);"));
}
