#include <iostream>
using namespace std;

int main(void) {
	int input;
	cout << "[input]: ";
	cin >> input;

	if (input <= 0) {
		cout << "[err]: invalid input" << endl;
		return 1;
	}

	for (int number = 1; number <= input; number++) {
		int sqrd = number * number;
		int num = 0;
		int cpy = number;

		while (cpy > 0) {
			num++;
			cpy /= 10;
		}

		int div = 1;
		for (int i = 0; i < num; i++) {
			div *= 10;
		}

		int acpy = sqrd / div;
		int bcpy = sqrd % div;

		if (acpy + bcpy == number && (bcpy != 0 || number == 1)) {
			cout << " kaprekar number :: " << number << endl;
		}
	}
	return 0;
}