#include "../../src/SQLiteConstraints.h"

#include <gmock/gmock.h>

using ::testing::Eq;


TEST(Constraint, returnsCorrectStringWithoutPrimaryKeyThatMayBeNull)
{
    auto defaultConstructed = SQLiteConstraints(Constraint::NO_CONSTRAINT);
    EXPECT_THAT(defaultConstructed.toString(), Eq(""));
}

TEST(Constraint, returnsCorrectStringWithoutPrimaryKeyThatMayNotBeNull)
{
    auto constraint = SQLiteConstraints(Constraint::NOT_NULL);
    EXPECT_THAT(constraint.toString(), Eq(" NOT NULL "));
}


TEST(Constraint, returnsCorrectStringWithPrimaryKey)
{
    auto justPrimary = SQLiteConstraints(Constraint::PRIMARY_KEY);
    EXPECT_THAT(justPrimary.toString(), Eq(" PRIMARY KEY "));

    auto bothPrimaryAndNotNull = SQLiteConstraints(Constraint::PRIMARY_KEY, Constraint::NOT_NULL);
    EXPECT_THAT(bothPrimaryAndNotNull.toString(), Eq(" PRIMARY KEY "));
}