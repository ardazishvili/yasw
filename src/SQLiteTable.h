#ifndef YASW_SQLITETABLE_H
#define YASW_SQLITETABLE_H

#include "SQLiteColumn.h"
#include "Table.h"
#include "misc.h"

#include <memory>
#include <vector>

template <typename... Columns>
class SQLiteTable : public Table
{
  public:
    using columns_types = std::tuple<typename extract_args<Columns>::type...>;
    using table_types = std::tuple<Columns...>;

    SQLiteTable(const std::string& name, Columns... columns)
        : m_name(name)
        , m_columns(std::make_tuple(std::move(columns)...))
    {}

    std::string toString() const override
    {
        std::string result = "CREATE TABLE " + m_name + "(";
        for (int i = 0; i < size(); ++i) {
            for_index(
                i, m_columns, [&result](const auto& obj) { result += obj->toString() + ","; });
        }
        // TODO ugly removal of trailing comma
        result.pop_back();
        return result + ");";
    }

    int size() const
    {
        return std::tuple_size<decltype(m_columns)>();
    }

  private:
    std::string m_name;
    table_types m_columns;
};

template <typename... Cols>
std::unique_ptr<SQLiteTable<Cols...>> createTable(const std::string& name, Cols... cols)
{
    return std::make_unique<SQLiteTable<Cols...>>(name, std::move(cols)...);
}

#endif    // YASW_SQLITETABLE_H
