#ifndef YASW_COLUMNMOCK_H
#define YASW_COLUMNMOCK_H

#include <gmock/gmock.h>

#include "../../../src/Column.h"

class ColumnMock : public Column {
public:
    typedef int element_type; // stub for tests only
    MOCK_CONST_METHOD0(toString, std::string());
};

#endif //YASW_COLUMNMOCK_H
