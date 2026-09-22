#include <iostream>
#include <bits/stdc++.h>

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

	int counter = 0;
	int number = 1;

	for (int i = 0; i <= rows; i++) {
		int printed = 0;
		while (printed < i) {
			int divisors = 0;
			for (int i = 1; i <= number; i++) {
				if (number % i == 0) {
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