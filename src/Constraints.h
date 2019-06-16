#ifndef YASW_CONSTRAINTS_H
#define YASW_CONSTRAINTS_H

#include <string>

class Constraints {
public:
    virtual std::string toString() const = 0;

    virtual ~Constraints() = default;
};


#endif    // YASW_CONSTRAINTS_H
