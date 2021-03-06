#ifndef YASW_SQLITEDATABASE_H
#define YASW_SQLITEDATABASE_H

#include <string>
#include <memory>

#include "SQLInterface.h"
#include "Database.h"

class SQLiteDatabase : public Database {
public:
    SQLiteDatabase(const std::string& filename,
                   std::unique_ptr<SQLInterface>&& interface,
                   bool isNew = false);
    virtual void createTable(std::unique_ptr<Table>&& table) override;

private:
    bool fileExist(const std::string& filename) const;

    std::unique_ptr<SQLInterface> m_iface;
    std::unique_ptr<sqlite3*> m_sqliteDb;
};

SQLiteDatabase openDatabase(const std::string &filename);
SQLiteDatabase createDatabase(const std::string &filename);


#endif //YASW_SQLITEDATABASE_H
