#ifndef YASW_SQLITETABLE_H
#define YASW_SQLITETABLE_H

#include <vector>
#include <memory>

#include "Table.h"
#include "SQLiteColumn.h"

using Columns = std::vector<std::unique_ptr<Column>>;
class SQLiteTable : public Table {
public:
    SQLiteTable(const std::string& name, Columns&& columns);
    std::string toString() const override;

private:
    std::string m_name;
    Columns m_columns;
};

template <typename ... Cols>
std::unique_ptr<SQLiteTable> createTable(const std::string& name, Cols... cols)
{
    Columns columns;
    (columns.push_back(std::move(cols)), ...);
    return std::make_unique<SQLiteTable>(name, std::move(columns));
}


#endif //YASW_SQLITETABLE_H
