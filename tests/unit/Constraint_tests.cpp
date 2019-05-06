#include <gmock/gmock.h>

#include "../../SQLiteConstraint.h"

using ::testing::Eq;


TEST(Constraint, returnsCorrectStringWithoutPrimaryKeyThatMayBeNull)
{
    auto defaultConstructed = SQLiteConstraint();
    EXPECT_THAT(defaultConstructed.toString(), Eq(""));

    auto constructedWithAgrs = SQLiteConstraint(false, false);
    EXPECT_THAT(constructedWithAgrs.toString(), Eq(""));
}

TEST(Constraint, returnsCorrectStringWithoutPrimaryKeyThatMayNotBeNull)
{
    auto constraint = SQLiteConstraint(false, true);
    EXPECT_THAT(constraint.toString(), Eq(" NOT NULL "));
}


TEST(Constraint, returnsCorrectStringWithPrimaryKey)
{
    auto justPrimary = SQLiteConstraint(true, false);
    EXPECT_THAT(justPrimary.toString(), Eq(" PRIMARY KEY "));

    auto bothPrimaryAndNotNull = SQLiteConstraint(true, true);
    EXPECT_THAT(bothPrimaryAndNotNull.toString(), Eq(" PRIMARY KEY "));
}