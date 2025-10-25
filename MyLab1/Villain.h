#ifndef VILLAIN_H
#define VILLAIN_H

#include "Base_v5.h"
#include <string>
#include <vector>

class Villain : public Base_v5 {
    std::string name;
    std::string weapon;
    std::string crime;      // какое злодеяние совершил
    std::string location;   // где обитает
    std::vector<std::string> skills;
public:
    Villain();
    Villain(const std::string& name, const std::string& weapon, const std::string& crime, const std::string& loc, const std::vector<std::string>& skills);
    Villain(const Villain& other);
    ~Villain();

    void setName(const std::string& s); std::string getName() const;
    void setWeapon(const std::string& w); std::string getWeapon() const;
    void setCrime(const std::string& c); std::string getCrime() const;
    void setLocation(const std::string& l); std::string getLocation() const;
    void setSkills(const std::vector<std::string>& s); std::vector<std::string> getSkills() const;

    void print() const override;
    void save(std::ofstream& out) const override;
    Base_v5* clone() const override { return new Villain(*this); }
    std::string type() const override { return "VILLAIN"; }
};

#endif // VILLAIN_H
