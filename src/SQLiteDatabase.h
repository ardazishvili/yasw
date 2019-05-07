#ifndef YASW_SQLITEDATABASE_H
#define YASW_SQLITEDATABASE_H

#include <string>
#include <memory>

#include "SQLInterface.h"
#include "Database.h"

class SQLiteDatabase : public Database {
public:
    SQLiteDatabase(const std::string& filename,
                   std::unique_ptr<SQLInterface>&& interface);
    virtual void createTable(std::unique_ptr<Table>&& table) override;

private:
    std::unique_ptr<SQLInterface> m_iface;
    std::unique_ptr<sqlite3*> m_sqliteDb;
};

SQLiteDatabase createDataBase(const std::string& filename);


#endif //YASW_SQLITEDATABASE_H
