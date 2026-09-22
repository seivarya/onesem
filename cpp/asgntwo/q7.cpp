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

	while (input != 1 && input != 4) {
		int sum = 0;
		while (input > 0) {
			int digit = input % 10;
			sum += digit * digit;
			input /= 10;
		}
		input = sum;
	}

	if (input == 1) {
		cout << "[info] :: [happy number]" << endl;
	} else if (input == 4) {
		cout << "[info] :: [unhappy number :(]" << endl;
	} else {
		cout << "[err]: unexpected err" << endl;
	}
}