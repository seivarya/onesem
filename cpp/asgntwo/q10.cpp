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

	int is_self = 1;
	for (int i = 0; i < digits; i++) {
		int div = 1;
		for (int p = 0; p < digits - 1 - i; p++) {
			div *= 10;
		}
		int num = (input / div) % 10;

		int counter = 0;
		int ccopy = input;
		while (ccopy > 0) {
			int temp = ccopy % 10;
			if (temp == i) {
				counter++;
			}
			ccopy /= 10;
		}

		if (counter != num) {
			is_self = 0;
			break;
		}
	}

	if (is_self) {
		cout << "[ self descriptive ]" << endl;
	} else {
		cout << "[ not self descriptive ]" << endl;
	}

	return 0;
}