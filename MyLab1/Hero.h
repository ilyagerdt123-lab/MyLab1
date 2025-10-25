#ifndef HERO_H
#define HERO_H

#include "Base_v5.h"
#include <string>
#include <vector>

class Hero : public Base_v5 {
    std::string name;
    std::string weapon;
    std::vector<std::string> skills; // основные навыки
public:
    Hero();
    Hero(const std::string& name, const std::string& weapon, const std::vector<std::string>& skills);
    Hero(const Hero& other);
    ~Hero();

    void setName(const std::string& s); std::string getName() const;
    void setWeapon(const std::string& w); std::string getWeapon() const;
    void setSkills(const std::vector<std::string>& s); std::vector<std::string> getSkills() const;

    void print() const override;
    void save(std::ofstream& out) const override;
    Base_v5* clone() const override { return new Hero(*this); }
    std::string type() const override { return "HERO"; }
};

#endif // HERO_H
