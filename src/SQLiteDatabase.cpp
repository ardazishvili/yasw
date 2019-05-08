

#include <fstream>

#include "SQLiteDatabase.h"
#include "SQLiteInterface.h"

SQLiteDatabase::SQLiteDatabase(const std::string& filename,
                               std::unique_ptr<SQLInterface>&& interface,
                               bool isNew) :
    m_iface(std::move(interface)),
    m_sqliteDb(std::make_unique<sqlite3*>())
{
    if (isNew && fileExist(filename)) {
        throw std::runtime_error("Database already exists");
    }
    int flags = isNew ? SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE : SQLITE_OPEN_READWRITE;
    auto rc = m_iface->open(filename.c_str(), m_sqliteDb.get(), flags, nullptr);
    if (rc) {
        throw std::runtime_error("Cant open db: " + filename);
    }

}

void SQLiteDatabase::createTable(std::unique_ptr<Table>&& table)
{

}

bool SQLiteDatabase::fileExist(const std::string& name) const {
    std::ifstream file(name);
    return file.good();

}


SQLiteDatabase openDatabase(const std::string &filename) {
    return SQLiteDatabase(filename, std::make_unique<SQLiteInterface>());
}

SQLiteDatabase createDatabase(const std::string &filename) {
    return SQLiteDatabase(filename, std::make_unique<SQLiteInterface>(), true);
}
