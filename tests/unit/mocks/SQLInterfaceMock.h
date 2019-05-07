#ifndef YASW_SQLINTERFACEMOCK_H
#define YASW_SQLINTERFACEMOCK_H

#include <gmock/gmock.h>

#include "../../../src/SQLInterface.h"

class SQLInterfaceMock : public SQLInterface {
public:
    MOCK_METHOD2(open, int(const char*, sqlite3**));
    MOCK_METHOD5(exec, int ( sqlite3*,
                             const char*,
                             int (*)(void*,int,char**,char**),
                             void*,
                             char**));
    MOCK_METHOD1(close, int(sqlite3* ));
    MOCK_METHOD1(free, void(void*));
};

#endif //YASW_SQLINTERFACEMOCK_H
