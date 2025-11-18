#include "Hero.h"
#include <iostream>

Hero::Hero() : name("не изветен"), weapon("нет"), skills() {
    std::cout << "Hero: default constructor\n";
}

Hero::Hero(const std::string& name_, const std::string& weapon_, const std::vector<std::string>& skills_)
    : name(name_), weapon(weapon_), skills(skills_) {
    std::cout << "Hero: parameter constructor\n";
}

Hero::Hero(const Hero& other)
    : name(other.name), weapon(other.weapon), skills(other.skills) {
    std::cout << "Hero: copy constructor\n";
}

Hero::~Hero() {
    std::cout << "Hero: destructor\n";
}

void Hero::setName(const std::string& s) { name = s; }
std::string Hero::getName() const { return name; }
void Hero::setWeapon(const std::string& w) { weapon = w; }
std::string Hero::getWeapon() const { return weapon; }
void Hero::setSkills(const std::vector<std::string>& s) { skills = s; }
std::vector<std::string> Hero::getSkills() const { return skills; }

void Hero::print() const {
    std::cout << "[Hero] " << name << ", weapon=" << weapon << ", skills={";
    for (size_t i = 0; i < skills.size(); ++i) {
        std::cout << skills[i];
        if (i + 1 < skills.size()) std::cout << "; ";
    }
    std::cout << "}\n";
}

void Hero::save(std::ofstream& out) const {
    // HERO
    // <name>
    // <weapon>
    // <skills_count>
    // <skill1>
    // ...
    out << "HERO" << '\n';
    out << name << '\n';
    out << weapon << '\n';
    out << skills.size() << '\n';
    for (const auto& s : skills) out << s << '\n';
}
