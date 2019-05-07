#ifndef YASW_COLUMNMOCK_H
#define YASW_COLUMNMOCK_H

#include <gmock/gmock.h>

#include "../../../src/Column.h"

class ColumnMock : public Column {
public:
    MOCK_CONST_METHOD0(toString, std::string());
};

#endif //YASW_COLUMNMOCK_H
