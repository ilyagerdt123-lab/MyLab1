#include "Villain.h"
#include <iostream>

Villain::Villain() : name("unknown"), weapon("none"), crime("none"), location("unknown"), skills() {
    std::cout << "Villain: default constructor\n";
}

Villain::Villain(const std::string& name_, const std::string& weapon_, const std::string& crime_, const std::string& loc_, const std::vector<std::string>& skills_)
    : name(name_), weapon(weapon_), crime(crime_), location(loc_), skills(skills_) {
    std::cout << "Villain: parameter constructor\n";
}

Villain::Villain(const Villain& other)
    : name(other.name), weapon(other.weapon), crime(other.crime), location(other.location), skills(other.skills) {
    std::cout << "Villain: copy constructor\n";
}

Villain::~Villain() {
    std::cout << "Villain: destructor\n";
}

void Villain::setName(const std::string& s) { name = s; }
std::string Villain::getName() const { return name; }
void Villain::setWeapon(const std::string& w) { weapon = w; }
std::string Villain::getWeapon() const { return weapon; }
void Villain::setCrime(const std::string& c) { crime = c; }
std::string Villain::getCrime() const { return crime; }
void Villain::setLocation(const std::string& l) { location = l; }
std::string Villain::getLocation() const { return location; }
void Villain::setSkills(const std::vector<std::string>& s) { skills = s; }
std::vector<std::string> Villain::getSkills() const { return skills; }

void Villain::print() const {
    std::cout << "[Villain] " << name << ", weapon=" << weapon << ", crime=" << crime << ", location=" << location << ", skills={";
    for (size_t i = 0; i < skills.size(); ++i) {
        std::cout << skills[i];
        if (i + 1 < skills.size()) std::cout << "; ";
    }
    std::cout << "}\n";
}

void Villain::save(std::ofstream& out) const {
    // VILLAIN
    // <name>
    // <weapon>
    // <crime>
    // <location>
    // <skills_count>
    // <skill1>
    out << "VILLAIN" << '\n';
    out << name << '\n';
    out << weapon << '\n';
    out << crime << '\n';
    out << location << '\n';
    out << skills.size() << '\n';
    for (const auto& s : skills) out << s << '\n';
}
