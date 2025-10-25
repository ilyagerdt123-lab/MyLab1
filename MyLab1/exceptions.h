#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class FactoryException : public std::exception {
    std::string msg;
public:
    FactoryException(const std::string& m) : msg(m) {}
    const char* what() const noexcept override { return msg.c_str(); }
};

#endif // EXCEPTIONS_H
