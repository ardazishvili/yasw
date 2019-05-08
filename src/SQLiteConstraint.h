#ifndef YASW_SQLITE_CONSTRAINT_H
#define YASW_SQLITE_CONSTRAINT_H

#include <string>
#include <memory>

#include "Constraint.h"

class SQLiteConstraint : public Constraint {
public:
    SQLiteConstraint() = default;
    SQLiteConstraint(bool primaryKey, bool notNull);
    std::string toString() const override;

private:
    bool m_isPrimary { false };
    bool m_notNull { false };
};

std::unique_ptr<SQLiteConstraint> createNoConstraints();
// TODO use variadics to add constraints, e.g. createConstraint(PRIMARY_KEY, NOT_NULL) or createConstraint(UNIQUE)
std::unique_ptr<SQLiteConstraint> createConstraint(bool primaryKey, bool notNull);


#endif //YASW_SQLITE_CONSTRAINT_H
