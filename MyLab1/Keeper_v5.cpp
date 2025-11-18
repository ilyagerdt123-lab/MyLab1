#include "Keeper_v5.h"
#include "Hero.h"
#include "Villain.h"
#include "Monster.h"
#include <iostream>
#include <sstream>

Keeper_v5::Keeper_v5() : items(nullptr), size(0), capacity(0) {
    resize(4);
    std::cout << "Keeper_v5: конструктор по умолчанию\n";
}

void Keeper_v5::resize(int newCap) {
    if (newCap <= capacity) return;
    Base_v5** newItems = new Base_v5 * [newCap];
    for (int i = 0; i < size; ++i) newItems[i] = items[i];
    for (int i = size; i < newCap; ++i) newItems[i] = nullptr;
    delete[] items;
    items = newItems;
    capacity = newCap;
}

Keeper_v5::Keeper_v5(const Keeper_v5& other) : items(nullptr), size(0), capacity(0) {
    resize(other.capacity);
    for (int i = 0; i < other.size; ++i) {
        items[i] = other.items[i]->clone();
    }
    size = other.size;
    std::cout << "Keeper_v5: конструктор копирования\n";
}

Keeper_v5& Keeper_v5::operator=(const Keeper_v5& other) {
    if (this == &other) return *this;
    clear();
    resize(other.capacity);
    for (int i = 0; i < other.size; ++i) items[i] = other.items[i]->clone();
    size = other.size;
    std::cout << "Keeper_v5: оператор присваивания\n";
    return *this;
}

Keeper_v5::~Keeper_v5() {
    clear();
    delete[] items;
    std::cout << "Keeper_v5: деструктор\n";
}

void Keeper_v5::add(Base_v5* obj) {
    if (!obj) throw FactoryException("Попытка добавить нулевой указатель");
    if (size >= capacity) resize(capacity * 2);
    items[size++] = obj;
}

void Keeper_v5::removeAt(int index) {
    if (index < 0 || index >= size) throw FactoryException("Индекс вне диапазона");
    delete items[index];
    for (int i = index; i < size - 1; ++i) items[i] = items[i + 1];
    items[--size] = nullptr;
}

Base_v5* Keeper_v5::getAt(int index) const {
    if (index < 0 || index >= size) throw FactoryException("Индекс вне диапазона");
    return items[index];
}

void Keeper_v5::clear() {
    for (int i = 0; i < size; ++i) {
        delete items[i]; items[i] = nullptr;
    }
    size = 0;
}

void Keeper_v5::saveToFile(const std::string& filename) const {
    std::ofstream out(filename.c_str());
    if (!out) throw FactoryException(std::string("Не удалось открыть файл для записи: ") + filename);
    out << size << '\n';
    for (int i = 0; i < size; ++i) {
        items[i]->save(out);
    }
    out.close();
    std::cout << "Данные сохранены в файл: " << filename << '\n';
}

void Keeper_v5::loadFromFile(const std::string& filename) {
    std::ifstream in(filename.c_str());
    if (!in) throw FactoryException(std::string("Не удалось открыть файл для чтения: ") + filename);
    clear();
    int n = 0;
    in >> n;
    std::string dummy;
    std::getline(in, dummy); // consume endline
    resize(n > 4 ? n : 4);
    for (int i = 0; i < n; ++i) {
        std::string type;
        if (!std::getline(in, type)) throw FactoryException("Неожиданный конец файла при чтении типа объекта");
        if (type == "HERO") {
            std::string name; std::getline(in, name);
            std::string weapon; std::getline(in, weapon);
            int skills_count; in >> skills_count; std::getline(in, dummy);
            std::vector<std::string> skills;
            for (int k = 0; k < skills_count; ++k) { std::string s; std::getline(in, s); skills.push_back(s); }
            Hero* h = new Hero(name, weapon, skills);
            add(h);
        }
        else if (type == "VILLAIN") {
            std::string name; std::getline(in, name);
            std::string weapon; std::getline(in, weapon);
            std::string crime; std::getline(in, crime);
            std::string location; std::getline(in, location);
            int skills_count; in >> skills_count; std::getline(in, dummy);
            std::vector<std::string> skills;
            for (int k = 0; k < skills_count; ++k) { std::string s; std::getline(in, s); skills.push_back(s); }
            Villain* v = new Villain(name, weapon, crime, location, skills);
            add(v);
        }
        else if (type == "MONSTER") {
            std::string name; std::getline(in, name);
            std::string description; std::getline(in, description);
            Monster* m = new Monster(name, description);
            add(m);
        }
        else {
            throw FactoryException(std::string("Неизвестный тип объекта в файле: ") + type);
        }
    }
    in.close();
    std::cout << "Данные загружены из файла: " << filename << '\n';
}
