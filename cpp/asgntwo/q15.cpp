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

	int digits = 0;
	int copy = input;
	while (copy > 0) {
		digits++;
		copy /= 10;
	}

	int mult = 1;
	for (int i = 1; i < digits; i++) {
		mult *= 10;
	}

	int is_circular = 1;
	int current = input;

	for (int r = 0; r < digits; r++) {
		int divisors = 0;
		for (int d = 1; d <= current; d++) {
			if (current % d == 0) {
				divisors++;
			}
		}

		if (divisors != 2) {
			is_circular = 0;
			break;
		}

		int last_digit = current % 10;
		current = (last_digit * mult) + (current / 10);
	}

	if (is_circular) {
		cout << "[ circular prime ]" << endl;
	} else {
		cout << "[ not circular prime ]" << endl;
	}

	return 0;
}