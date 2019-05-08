#ifndef YASW_SQLITEINTERFACE_H
#define YASW_SQLITEINTERFACE_H

#include "SQLInterface.h"

class SQLiteInterface : public SQLInterface {
public:
    int open(const char *filename,
             sqlite3 **ppDb,
             int flags,
             const char *zVfs) override;
    int exec(sqlite3*db ,
             const char *sql,
             int (*callback)(void*,int,char**,char**),
             void* arg,
             char **errmsg) override;
    void free(void* arg) override;
    int close(sqlite3* db) override;
};


#endif //YASW_SQLITEINTERFACE_H
