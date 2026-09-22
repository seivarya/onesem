#include <iostream>
using namespace std;

int main(void) {
	int number;
	cout << "[input]:: enter ";
	cin >> number;

	if (number <= 0) {
		cout << "[err]: invalid input" << endl;
		return 1;
	}

	int num = number;
	int powmax = 0;
	int powmaxdig = 0;
	while (num != 0) {
		int divisors = 0;
		int divsum = 0;
		int copy = num;
		int sum = 0;

		while (copy > 0) {
			int digit = copy % 10;
			sum += digit;
			copy = copy / 10;
		}
		for (int i = 1; i <= num; i++) {
			if (num % i == 0) {
				divisors++;
			}
		}
		int power_score = divisors * sum;

		if (power_score > powmax) {
			powmax = power_score;
			powmaxdig = num;
		}

		num--;
	}
	cout << "[info] :: [power max] : " << powmax << endl;
	cout << "[info] :: [power max digit] : " << powmaxdig << endl;
}