#include <iostream>
using namespace std;

// last part left
int main(void) {
	int N{0};
	cout << "[input]: ";
	cin >> N;

	if (N <= 0) {
		cout << "[err]: invalid input" << endl;
		return 1;
	}

	int total = 0;
	int largest = 0;
	int smallest = 1;
	int sum = 0;
	int temp = 0;

	int max_row = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int M = i * j;
			int properties = 0;

			int divisors = 0;
			int divsum = 0;

			for (int i = 1; i <= M; i++) {
				if (M % i == 0) {
					divisors++;
					if (i != M) {
						divsum += i;
					}
				}
			}

			if (divisors == 2) {
				properties++;
			}

			if (divsum == M) {
				properties++;
			}

			int copy = M;
			int palin = 0;
			int arm = 0;
			int digits = 0;
			int tmp = M;

			while (tmp > 0) {
				digits += 1;
				tmp /= 10;
			}

			while (copy > 0) {
				int digit = copy % 10;
				palin = palin * 10 + digit;
				int powval = 1;
				for (int pnum = 1; pnum <= digits; pnum++) {
					powval *= digit;
				}
				arm += powval;

				copy /= 10;
			}
			if (arm == M) {
				properties++;
			}
			if (palin == M) {
				properties++;
			}

			if (properties == 2) {

				if (temp == 0) {
					smallest = M;
					temp = 1;
				}
				if (M > largest) {
					largest = M;
				}
				sum += M;
				total++;
			}
		}
	}
	cout << "[info] :: [total number of such values] : " << total << endl;
	cout << "[info] :: [largest] : " << largest << endl;
	cout << "[info] :: [smallest] : " << smallest << endl;
	cout << "[info] :: [sum] : " << sum << endl;
}

// prime palin arm perf