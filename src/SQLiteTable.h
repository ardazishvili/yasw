#ifndef YASW_SQLITETABLE_H
#define YASW_SQLITETABLE_H

#include <vector>
#include <memory>

#include "Table.h"
#include "SQLiteColumn.h"



using SQLiteColumns = std::vector<std::unique_ptr<SQLiteColumn>>;
class SQLiteTable : public Table {
public:
    SQLiteTable(SQLiteColumns columns);

private:
    SQLiteColumns m_columns;
};


#endif //YASW_SQLITETABLE_H
