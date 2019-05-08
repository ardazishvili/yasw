#include "SQLiteConstraint.h"


SQLiteConstraint::SQLiteConstraint(bool primaryKey, bool notNull)
    : m_isPrimary(primaryKey), m_notNull(notNull)
{ }

std::string SQLiteConstraint::toString() const
{
    std::string result = m_isPrimary ? " PRIMARY KEY " : "";
    result = (m_notNull && !m_isPrimary) ? result + " NOT NULL " : result;
    return result;
}

std::unique_ptr<SQLiteConstraint> createNoConstraints() {
    return std::make_unique<SQLiteConstraint>();
}

std::unique_ptr<SQLiteConstraint> createConstraint(bool primaryKey, bool notNull) {
    return std::make_unique<SQLiteConstraint>(primaryKey, notNull);
}
