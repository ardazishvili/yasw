#ifndef YASW_SQLITECOLUMN_H
#define YASW_SQLITECOLUMN_H

#include <map>

#include "Column.h"
#include "SQLiteConstraint.h"
#include "misc.h"

template <typename T>
class SQLiteColumn : public Column {
public:
    typedef T element_type;
    SQLiteColumn(const std::string& name, std::unique_ptr<Constraint>&& constraint)
    : m_name(name), m_constraint(std::move(constraint))
    {
    }

    std::string toString() const override
    {
        return m_name + " " + cppToSqlType[std::string(type_name<T>())] + m_constraint->toString();
    }

private:
    static std::map<std::string, std::string> cppToSqlType;
    std::string m_name;
    std::unique_ptr<Constraint> m_constraint;
};

template <typename T>
std::map<std::string, std::string> SQLiteColumn<T>::cppToSqlType = {
        { "std::__cxx11::basic_string<char>", "TEXT" },
        { "int", "INTEGER" }
};


template <typename T>
std::unique_ptr<SQLiteColumn<T>> createColumn(const std::string& name,
                                           std::unique_ptr<Constraint>&& constraint)
{
    return std::make_unique<SQLiteColumn<T>>(name, std::move(constraint));
}


#endif //YASW_SQLITECOLUMN_H
