#include "Base_v5.h"

Base_v5::Base_v5() { std::cout << "Base_v5: default constructor\n"; }
Base_v5::Base_v5(const Base_v5&) { std::cout << "Base_v5: copy constructor\n"; }
Base_v5::~Base_v5() { std::cout << "Base_v5: destructor\n"; }
