#ifndef YASW_OBJECT_H
#define YASW_OBJECT_H

#include <string>
#include <vector>

class Object
{
public:
    virtual std::string content() const = 0;
};

#endif    // YASW_OBJECT_H
