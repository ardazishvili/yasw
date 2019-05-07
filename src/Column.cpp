#include <map>

#include "Column.h"

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
    return m_name + " " + datatypeMapper[m_type] + m_constraint->toString() + ",";
}