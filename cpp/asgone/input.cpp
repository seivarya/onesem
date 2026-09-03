#include <iostream>

int getint() {
	int var { };

	std::cout << "[input]: enter an integer" << std::endl;
	std::cin >> var;

	return var;
}
