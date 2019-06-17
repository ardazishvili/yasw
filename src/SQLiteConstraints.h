#ifndef YASW_SQLITE_CONSTRAINT_H
#define YASW_SQLITE_CONSTRAINT_H

#include "Constraints.h"
#include "misc.h"

#include <map>
#include <memory>

enum class Constraint
{
    PRIMARY_KEY = 0,
    NOT_NULL,
    UNIQUE,
    NO_CONSTRAINT
};

template <typename... Cons>
class SQLiteConstraints : public Constraints
{
public:
    SQLiteConstraints(Cons... constraints)
        : m_constraints{std::make_tuple(constraints...)}
    {}

    std::string toString() const override
    {
        std::string result;
        for (int i = 0; i < size(); ++i) {
            for_index(i, m_constraints, [&result](const auto& obj) {
                auto it = m_constraintToStringMap.find(obj);
                if (it != m_constraintToStringMap.end()) {
                    const bool notNullAfterPrimary =
                        (it->second == " NOT NULL ") &&
                        (result.find("PRIMARY KEY") != std::string::npos);
                    if (!notNullAfterPrimary)
                        result += it->second;
                }
            });
        }
        return result;
    }

    int size() const
    {
        return std::tuple_size<decltype(m_constraints)>();
    }

private:
    using constraints = std::tuple<Cons...>;
    constraints m_constraints;
    static const std::map<Constraint, std::string> m_constraintToStringMap;
};

std::unique_ptr<SQLiteConstraints<>> createNoConstraints();
template <typename... Constraints>
std::unique_ptr<SQLiteConstraints<Constraints...>> createConstraint(Constraints... constraints)
{
    return std::make_unique<SQLiteConstraints<Constraints...>>(constraints...);
}

template <typename... Cons>
const std::map<Constraint, std::string> SQLiteConstraints<Cons...>::m_constraintToStringMap = {
    {Constraint::PRIMARY_KEY, " PRIMARY KEY "},
    {Constraint::NOT_NULL, " NOT NULL "},
    {Constraint::UNIQUE, " UNIQUE "},
    {Constraint::NO_CONSTRAINT, ""}};

#endif    // YASW_SQLITE_CONSTRAINT_H
