#include "SQLiteTable.h"

SQLiteTable::SQLiteTable(const std::string& name, Columns&& columns)
    : m_name(name), m_columns(move(columns)) {

}

std::string SQLiteTable::toString() const {
    std::string result = "CREATE TABLE " + m_name + "(";
    for (auto& column : m_columns)
    {
        result += column->toString() + ",";
    }
    // TODO ugly removal of trailing comma
    result.pop_back();
    return result + ");";
}
