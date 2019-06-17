#include "../../../src/Constraints.h"

#include <gmock/gmock.h>

class ConstraintMock : public Constraints
{
public:
    MOCK_CONST_METHOD0(toString, std::string());
};