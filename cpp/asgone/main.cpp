#include <iostream>

int getint();

int main(void) {
	int x { getint() };
	int y { getint() };

	std::cout << x << " + " << y << " is " << x + y << std::endl;
	return 0;
}
