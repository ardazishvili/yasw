#ifndef YASW_CONSTRAINT_H
#define YASW_CONSTRAINT_H

class Constraint {
public:
    virtual std::string toString() const = 0;

    virtual ~Constraint() = default;
};


#endif //YASW_CONSTRAINT_H
