#ifndef YASW_SQLITECOLUMN_H
#define YASW_SQLITECOLUMN_H

#include "Column.h"
#include "SQLiteConstraint.h"

enum class Datatype {
    INTEGER,
    REAL,
    TEXT,
    BLOB,
    NUMERIC
};



class SQLiteColumn : public Column {
public:
    SQLiteColumn(const std::string& name, Datatype type, std::unique_ptr<Constraint>&& constraint);
    std::string toString() const override;

private:
    std::string m_name;
    Datatype m_type;
    std::unique_ptr<Constraint> m_constraint;
};


#endif //YASW_SQLITECOLUMN_H
