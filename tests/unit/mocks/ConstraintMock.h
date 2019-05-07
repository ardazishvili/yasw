#include <gmock/gmock.h>

#include "../../../src/Constraint.h"

class ConstraintMock : public Constraint {
public:
    MOCK_CONST_METHOD0(toString, std::string());
};