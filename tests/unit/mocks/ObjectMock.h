#ifndef YASW_OBJECTMOCK_H
#define YASW_OBJECTMOCK_H

#include <gmock/gmock.h>

#include "../../../src/Object.h"

class ObjectMock : public Object {
public:
    MOCK_CONST_METHOD0(content, std::string());
};

#endif //YASW_OBJECTMOCK_H
