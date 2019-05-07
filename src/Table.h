#ifndef YASW_TABLE_H
#define YASW_TABLE_H

class Table {
public:
    virtual std::string toString() const = 0;

    virtual ~Table() = default;
};

#endif //YASW_TABLE_H
