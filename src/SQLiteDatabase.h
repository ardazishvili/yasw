#ifndef YASW_SQLITEDATABASE_H
#define YASW_SQLITEDATABASE_H

#include <string>

#include "Database.h"

class SQLiteDatabase : public Database {
public:
    virtual void createTable();
};


#endif //YASW_DATABASE_H
