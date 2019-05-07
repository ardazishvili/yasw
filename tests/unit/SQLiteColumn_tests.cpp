#include <gmock/gmock.h>

#include "../../src/Column.h"

#include "mocks/ConstraintMock.h"

using ::testing::Eq;
using ::testing::Return;

TEST(Colums, returnsCorrectStringWithoutConstraints)
{
    std::unique_ptr<ConstraintMock> constraintMock { std::make_unique<ConstraintMock>() };
    EXPECT_CALL(*constraintMock, toString()).WillOnce(Return(""));
    auto c = SQLiteColumn("NAME", Datatype::TEXT, std::move(constraintMock));

    EXPECT_THAT(c.toString(), Eq("NAME TEXT,"));
}

TEST(Colums, returnsCorrectStringWithConstraints)
{
    std::unique_ptr<ConstraintMock> constraintMock { std::make_unique<ConstraintMock>() };
    EXPECT_CALL(*constraintMock, toString()).WillOnce(Return(" PRIMARY KEY "));
    auto c = SQLiteColumn("NAME", Datatype::TEXT, std::move(constraintMock));

    EXPECT_THAT(c.toString(), Eq("NAME TEXT PRIMARY KEY ,"));
}