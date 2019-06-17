#include "../../src/SQLiteColumn.h"
#include "mocks/ConstraintMock.h"

#include <gmock/gmock.h>

using ::testing::Eq;
using ::testing::Return;

TEST(Colums, returnsCorrectStringWithoutConstraints)
{
    std::unique_ptr<ConstraintMock> constraintMock{std::make_unique<ConstraintMock>()};
    EXPECT_CALL(*constraintMock, toString()).WillOnce(Return(""));
    auto c = SQLiteColumn<std::string>("NAME", std::move(constraintMock));

    EXPECT_THAT(c.toString(), Eq("NAME TEXT"));
}

TEST(Colums, returnsCorrectStringWithConstraints)
{
    std::unique_ptr<ConstraintMock> constraintMock{std::make_unique<ConstraintMock>()};
    EXPECT_CALL(*constraintMock, toString()).WillOnce(Return(" PRIMARY KEY "));
    auto c = SQLiteColumn<std::string>("NAME", std::move(constraintMock));

    EXPECT_THAT(c.toString(), Eq("NAME TEXT PRIMARY KEY "));
}