#include <iostream>

using namespace std;

int main(void) {
	int left;
	int right;
	cout << "[input]: ";
	cin >> left >> right;

	if (left <= 0 || right <= 0 || left >= right) {
		cout << "[err]: invalid range" << endl;
		return 1;
	}

	int number = left;
	int prev_prime = 0;
	int max = 0;
	int max_n1 = 0, max_n2 = 0;

	while (number <= right) {
		int divisors = 0;
		for (int div = 1; div <= number; div++) {
			if (number % div == 0) {
				divisors++;
			}
		}
		if (divisors == 2) {
			if (prev_prime != 0) {
				int gap = number - prev_prime;
				if (gap > max) {
					max = gap;
					max_n1 = prev_prime;
					max_n2 = number;
				}
			}
			prev_prime = number;
		}
		number++;
	}

	if (max == 0) {
		cout << "[err]: not enough primes in range" << endl;
		return 1;
	}

	cout << max_n1 << " :: " << max_n2 << endl;
	cout << max << endl;
	return 0;
}