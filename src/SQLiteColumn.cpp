#include <map>

#include "SQLiteColumn.h"

std::map<Datatype, std::string> datatypeMapper = {
        { Datatype::INTEGER, "INTEGER" },
        { Datatype::REAL, "REAL" },
        { Datatype::TEXT, "TEXT" },
        { Datatype::BLOB, "BLOB" },
        { Datatype::NUMERIC, "NUMERIC" },
};

SQLiteColumn::SQLiteColumn(const std::string &name, Datatype type, std::unique_ptr<Constraint>&& constraint) :
    m_name(name), m_type(type), m_constraint(std::move(constraint)) {

}

std::string SQLiteColumn::toString() const {
    return m_name + " " + datatypeMapper[m_type] + m_constraint->toString();
}

std::unique_ptr<SQLiteColumn> createColumn(const std::string &name,
                                           Datatype type,
                                           std::unique_ptr<Constraint> &&constraint) {
    return std::make_unique<SQLiteColumn>(name, type, std::move(constraint));
}
