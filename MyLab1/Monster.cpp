#include "Monster.h"
#include <iostream>

Monster::Monster() : name("unknown"), description("") {
    std::cout << "Monster: default constructor\n";
}

Monster::Monster(const std::string& name_, const std::string& description_)
    : name(name_), description(description_) {
    std::cout << "Monster: parameter constructor\n";
}

Monster::Monster(const Monster& other)
    : name(other.name), description(other.description) {
    std::cout << "Monster: copy constructor\n";
}

Monster::~Monster() {
    std::cout << "Monster: destructor\n";
}

void Monster::setName(const std::string& s) { name = s; }
std::string Monster::getName() const { return name; }
void Monster::setDescription(const std::string& d) { description = d; }
std::string Monster::getDescription() const { return description; }

void Monster::print() const {
    std::cout << "[Monster] " << name << " — " << description << "\n";
}

void Monster::save(std::ofstream& out) const {
    // MONSTER
    // <name>
    // <description>
    out << "MONSTER" << '\n';
    out << name << '\n';
    out << description << '\n';
}
