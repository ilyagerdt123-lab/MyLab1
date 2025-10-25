#ifndef MONSTER_H
#define MONSTER_H

#include "Base_v5.h"
#include <string>

class Monster : public Base_v5 {
    std::string name;
    std::string description;
public:
    Monster();
    Monster(const std::string& name, const std::string& description);
    Monster(const Monster& other);
    ~Monster();

    void setName(const std::string& s); std::string getName() const;
    void setDescription(const std::string& d); std::string getDescription() const;

    void print() const override;
    void save(std::ofstream& out) const override;
    Base_v5* clone() const override { return new Monster(*this); }
    std::string type() const override { return "MONSTER"; }
};

#endif // MONSTER_H
