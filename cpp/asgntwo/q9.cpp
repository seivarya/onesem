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
			num += 1;
			cpy /= 10;
		}

		int div = 1;

		while (num > 0) {
			div *= 10;
			num--;
		}

		if (sqrd % div == number) {
			cout << "[ automorphic number ] :: " << number << endl;
		}
	}
	return 0;
}