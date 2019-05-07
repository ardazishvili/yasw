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
