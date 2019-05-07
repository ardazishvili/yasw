#ifndef YASW_TABLEMOCK_H
#define YASW_TABLEMOCK_H

#include <gmock/gmock.h>

#include "../../../src/Table.h"

class TableMock : public Table {
public:
    MOCK_CONST_METHOD0(toString, std::string());
};

#endif //YASW_TABLEMOCK_H
