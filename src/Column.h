#ifndef YASW_COLUMN_H
#define YASW_COLUMN_H

#include <string>
#include <memory>

#include "SQLiteConstraint.h"

enum class Datatype {
    INTEGER,
    REAL,
    TEXT,
    BLOB,
    NUMERIC
};

class Column {
public:
    virtual std::string toString() const = 0;

    virtual ~Column() = default;
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


#endif //YASW_COLUMN_H
