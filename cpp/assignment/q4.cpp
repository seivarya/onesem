#include <iostream>

using namespace std;

int main(void)
{
	int input;
	cout << "[input]:: enter number for primes: ";
	cin >> input;

	int number = 2;
	for (int row = 1; row <= input; row++)
	{
		for (int space = 1; space <= input - row; space++)
		{
			cout << "  ";
		}

		int primes = (row * 2) - 1;
		int printed = 0;
		while (printed < primes)
		{
			int divisors = 0;
			for (int div = 1; div <= number; div++)
			{
				if (number % div == 0)
					divisors++;
			}

			if (divisors == 2)
			{
				cout << number << " ";
				printed++;
			}

			number++;
		}
		cout << endl;
	}
	for (int row = input - 1; row > 0; row--)
	{
		for (int space = 0; space < input - row; space++)
		{
			cout << "  ";
		}

		int primes = (row * 2) - 1;
		int printed = 0;
		while (printed < primes)
		{
			int divisors = 0;
			for (int div = 1; div <= number; div++)
			{
				if (number % div == 0)
					divisors++;
			}
			if (divisors == 2)
			{
				cout << number << " ";
				printed++;
			}
			number++;
		}
		cout << endl;
	}
}