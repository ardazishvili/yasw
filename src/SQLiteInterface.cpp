#include "SQLiteInterface.h"

int SQLiteInterface::open(const char *filename, sqlite3 **ppDb) {
    return sqlite3_open(filename, ppDb);
}

int SQLiteInterface::exec(sqlite3* db,
                          const char *sql,
                          int (*callback)(void *, int, char **, char **),
                          void* arg,
                          char **errmsg) {
    return sqlite3_exec(db, sql, callback, arg, errmsg);
}

void SQLiteInterface::free(void* arg) {
    sqlite3_free(arg);
}

int SQLiteInterface::close(sqlite3* db) {
    return sqlite3_close(db);
}
