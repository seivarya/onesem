#include <iostream>
using namespace std;

int main(void) {
	int A;
	int B;
	cout << "[input]: enter A & B :: ";
	cin >> A >> B;

	int winner = 0;
	int winnum = 0;

	for (int i = A; i <= B; i++) {
		int sum{0}, product{1}, digits{0}, divisors{0}, reverse{0};

		int is_greater_prod = 0;
		int is_greater_div = 0;
		int is_rev_prime = 0;

		int copy = i;
		while (copy > 0) {
			int digit = copy % 10;

			sum += digit;
			product *= digit;
			reverse = reverse * 10 + digit;

			copy /= 10;
			digits++;
		}

		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				divisors++;
			}
		}

		int revdiv = 0;
		for (int k = 1; k <= reverse; k++) {
			if (reverse % k == 0) {
				revdiv++;
			}
		}
		if (revdiv == 2) {
			is_rev_prime = 1;
		}
		if (product > sum) {
			is_greater_prod = 1;
		}
		if (divisors > digits) {
			is_greater_div = 1;
		}

		if (is_rev_prime && is_greater_div && is_greater_prod) {
			int score = product * divisors;
			cout << "[info] :: [winning number] : [ " << i << " ]" << endl;
			cout << "[info] :: [score] : [ " << score << " ]" << endl;
		}

		// cout << "[digit sum] : " << sum << endl;
		// cout << "[digit product] : " << product << endl;
		// cout << "[digit divisors] : " << divisors << endl;
		// cout << "[digits count] : " << digits << endl;
		// cout << "[digit reverse] : " << reverse << endl;
		// cout << "[digit score] : " << score << endl;
	}
}