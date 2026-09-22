#include <iostream>

using namespace std;

int main(void) {
	int input;
	cout << "[input] :: enter the number of rows: ";
	cin >> input;

	if (input <= 0) {
		cout << "[err]: invalid number of rows" << endl;
		return 1;
	}

	int rows = input;
	int number = 1;

	for (int r = 1; r <= rows; r++) {
		int printed = 0;
		while (printed < r) {
			int divisors = 0;
			for (int div = 1; div <= number; div++) {
				if (number % div == 0) {
					divisors++;
				}
			}
			if (divisors == 2) {
				cout << number << " ";
				printed++;
			}
			number++;
		}
		cout << endl;
	}
	return 0;
}