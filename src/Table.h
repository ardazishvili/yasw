#ifndef YASW_TABLE_H
#define YASW_TABLE_H

#include <vector>
#include <memory>

#include "Column.h"

class Table { };

using Columns = std::vector<std::unique_ptr<Column>>;
class SQLiteTable {
public:
    SQLiteTable(Columns columns);

private:
    Columns m_columns;
};


#endif //YASW_TABLE_H
