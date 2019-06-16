#include <gmock/gmock.h>

#include "../../../src/Constraints.h"

class ConstraintMock : public Constraints {
public:
    MOCK_CONST_METHOD0(toString, std::string());
};