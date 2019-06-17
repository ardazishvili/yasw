#ifndef YASW_SQLINTERFACEMOCK_H
#define YASW_SQLINTERFACEMOCK_H

#include "../../../src/SQLInterface.h"

#include <gmock/gmock.h>

class SQLInterfaceMock : public SQLInterface
{
public:
    MOCK_METHOD4(open, int(const char*, sqlite3**, int flags, const char* zVfs));
    MOCK_METHOD5(exec,
                 int(sqlite3*, const char*, int (*)(void*, int, char**, char**), void*, char**));
    MOCK_METHOD1(close, int(sqlite3*));
    MOCK_METHOD1(free, void(void*));
};

#endif    // YASW_SQLINTERFACEMOCK_H
