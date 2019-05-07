#ifndef YASW_DATABASE_H
#define YASW_DATABASE_H

#include "Table.h"

class Database {
public:
    virtual void createTable(std::unique_ptr<Table>&& table) = 0;

    virtual ~Database() = default;
};

#endif //YASW_DATABASE_H
