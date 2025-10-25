#ifndef BASE_V5_H
#define BASE_V5_H

#include <iostream>
#include <fstream>
#include <string>

class Base_v5 {
public:
    Base_v5();
    Base_v5(const Base_v5&);
    virtual ~Base_v5();

    virtual void print() const = 0;
    virtual void save(std::ofstream& out) const = 0;
    virtual Base_v5* clone() const = 0;
    virtual std::string type() const = 0;
};

#endif // BASE_V5_H
