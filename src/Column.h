#ifndef YASW_COLUMN_H
#define YASW_COLUMN_H

#include <memory>
#include <string>

class Column
{
public:
    virtual std::string toString() const = 0;

    virtual ~Column() = default;
};

#endif    // YASW_COLUMN_H
