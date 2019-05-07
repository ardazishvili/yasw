

#include "SQLiteDatabase.h"
#include "SQLiteInterface.h"

SQLiteDatabase::SQLiteDatabase(const std::string& filename,
                               std::unique_ptr<SQLInterface>&& interface) :
    m_iface(std::move(interface)),
    m_sqliteDb(std::make_unique<sqlite3*>())
{
    auto rc = m_iface->open(filename.c_str(), m_sqliteDb.get());
    if (rc) {
        throw std::runtime_error("Cant open db: " + filename);
    }

}

void SQLiteDatabase::createTable(std::unique_ptr<Table>&& table)
{

}


SQLiteDatabase createDataBase(const std::string& filename) {
    return SQLiteDatabase(filename, std::make_unique<SQLiteInterface>());
}