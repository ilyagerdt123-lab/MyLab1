#include <iostream>
#include <limits>
#include <vector>
#include "Keeper_v5.h"
#include "Hero.h"
#include "Villain.h"
#include "Monster.h"
#include "exceptions.h"

void printMenu() {
    std::cout << "\n--- Меню (Вариант 5 — Герои/Злодеи/Монстры) ---\n";
    std::cout << "1. Добавить положительного героя\n";
    std::cout << "2. Добавить злодея\n";
    std::cout << "3. Добавить монстра\n";
    std::cout << "4. Показать все\n";
    std::cout << "5. Удалить по индексу\n";
    std::cout << "6. Сохранить в файл\n";
    std::cout << "7. Загрузить из файла\n";
    std::cout << "0. Выход\n";
}

static std::vector<std::string> readSkillsInteractive() {
    std::vector<std::string> skills;
    std::cout << "Сколько навыков указать? ";
    int cnt = 0;
    if (!(std::cin >> cnt)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return skills;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (int i = 0; i < cnt; ++i) {
        std::string s;
        std::cout << "Навык " << (i + 1) << ": ";
        std::getline(std::cin, s);
        skills.push_back(s);
    }
    return skills;
}

int main() {
    setlocale(LC_ALL, "Russian");

    // Приветственный заголовок — мелкое улучшение, которое уместно для коммита
    std::cout << "=== Лабораторная работа №1 — Вариант 5: Герои / Злодеи / Монстры ===\n";
    std::cout << "Версия программы: 1.1\n";

    Keeper_v5 k;
    int choice = -1;
    while (choice != 0) {
        try {
            printMenu();
            std::cout << "Выберите пункт: ";
            if (!(std::cin >> choice)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Неверный ввод\n";
                continue;
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (choice == 1) {
                std::string name, weapon;
                std::cout << "Имя героя: "; std::getline(std::cin, name);
                std::cout << "Тип оружия: "; std::getline(std::cin, weapon);
                auto skills = readSkillsInteractive();
                Hero* h = new Hero(name, weapon, skills);
                k.add(h);
                std::cout << "Герой добавлен.\n";
            }
            else if (choice == 2) {
                std::string name, weapon, crime, location;
                std::cout << "Имя злодея: "; std::getline(std::cin, name);
                std::cout << "Тип оружия: "; std::getline(std::cin, weapon);
                std::cout << "Какое злодеяние совершил: "; std::getline(std::cin, crime);
                std::cout << "Где обитает: "; std::getline(std::cin, location);
                auto skills = readSkillsInteractive();
                Villain* v = new Villain(name, weapon, crime, location, skills);
                k.add(v);
                std::cout << "Злодей добавлен.\n";
            }
            else if (choice == 3) {
                std::string name, desc;
                std::cout << "Наименование монстра: "; std::getline(std::cin, name);
                std::cout << "Описание внешнего вида: "; std::getline(std::cin, desc);
                Monster* m = new Monster(name, desc);
                k.add(m);
                std::cout << "Монстр добавлен.\n";
            }
            else if (choice == 4) {
                int n = k.getSize();
                std::cout << "Всего объектов: " << n << "\n";
                for (int i = 0; i < n; ++i) {
                    std::cout << i << ": ";
                    k.getAt(i)->print();
                }
            }
            else if (choice == 5) {
                int idx; std::cout << "Индекс для удаления: "; std::cin >> idx; std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                k.removeAt(idx);
                std::cout << "Удалено\n";
            }
            else if (choice == 6) {
                std::string fname; std::cout << "Имя файла для сохранения: "; std::getline(std::cin, fname);
                k.saveToFile(fname);
            }
            else if (choice == 7) {
                std::string fname; std::cout << "Имя файла для загрузки: "; std::getline(std::cin, fname);
                k.loadFromFile(fname);
            }
            else if (choice == 0) {
                std::cout << "Выход...\n";
            }
            else {
                std::cout << "Неизвестный пункт\n";
            }
        }
        catch (const FactoryException& ex) {
            std::cout << "Ошибка: " << ex.what() << "\n";
        }
        catch (const std::exception& ex) {
            std::cout << "std::exception: " << ex.what() << "\n";
        }
    }
    return 0;
}
