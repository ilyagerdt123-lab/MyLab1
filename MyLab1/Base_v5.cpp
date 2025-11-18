#include "Base_v5.h"
#include <iostream>

Base_v5::Base_v5() { std::cout << "Base_v5: конструктор по умолчанию\n"; }
Base_v5::Base_v5(const Base_v5&) { std::cout << "Base_v5: конструктор копирования\n"; }
Base_v5::~Base_v5() { std::cout << "Base_v5: деструктор\n"; }
