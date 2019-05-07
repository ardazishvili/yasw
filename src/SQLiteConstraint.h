#ifndef YASW_SQLITE_CONSTRAINT_H
#define YASW_SQLITE_CONSTRAINT_H

#include <string>

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


#endif //YASW_SQLITE_CONSTRAINT_H
