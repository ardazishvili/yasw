#ifndef YASW_SQLINTERFACE_H
#define YASW_SQLINTERFACE_H

#include <sqlite3.h>

// TODO Interface currently is binded to SQLite3
class SQLInterface {
public:
    virtual int open(const char *filename, sqlite3 **ppDb) = 0;
    virtual int exec(
            sqlite3* db,                                /* An open database */
            const char *sql,                           /* SQL to be evaluated */
            int (*callback)(void*,int,char**,char**),  /* Callback function */
            void *arg,                                  /* 1st argument to callback */
            char **errmsg) = 0;                        /* Error msg written here */
    virtual void free(void* arg) = 0;
    virtual int close(sqlite3* db) = 0;

    virtual ~SQLInterface() = default;
};

#endif //YASW_SQLINTERFACE_H
