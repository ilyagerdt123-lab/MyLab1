#ifndef KEEPER_V5_H
#define KEEPER_V5_H

#include "Base_v5.h"
#include "exceptions.h"
#include <fstream>
#include <string>

class Keeper_v5 {
    Base_v5** items;
    int size;
    int capacity;
    void resize(int newCap);
public:
    Keeper_v5();
    Keeper_v5(const Keeper_v5& other);
    Keeper_v5& operator=(const Keeper_v5& other);
    ~Keeper_v5();

    void add(Base_v5* obj); // владеет obj
    void removeAt(int index);
    int getSize() const { return size; }
    Base_v5* getAt(int index) const;

    void clear();

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // KEEPER_V5_H
