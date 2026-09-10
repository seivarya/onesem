#include <iostream>

void first() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void second() {
	for (int i = 0; i <= 5; i++) {
		for (int j = 0; j < i; j++) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void third() {
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= i; j++) {
			std::cout << j;
		}
		std::cout  << std::endl;
	}
}

void fourth() {
	for(int i = 1; i <= 5; i++) {
		for (int j = 0; j < i; j++) {
			std::cout << i;
		}
		std::cout << std::endl;
	}


	}

void fifth() {
for (int i = 5; i > 0; i--) {
		for (int j = i; j > 0 ; j--) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

void sixth() {
	for (int i = 5; i > 0; i--) {
		for (int j = 1; j <= i; j++) {
			std::cout << j;
		}
		std::cout << std::endl;
	}
}

void seventh() {

}

int main(void) {
	// first();
	// second();
	 // third();
	// fourth();
	// fifth();
	sixth();
}

