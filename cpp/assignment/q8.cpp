// later::
#include <iostream>
using namespace std;
int main(void)
{
	int input;
	cout << "[input]: ";
	cin >> input;

	for (int number = 1; number <= input; number++) // bug :: odd number digits not handled!
	{
		int sqrd = number * number;
		int num = 0;
		int cpy = sqrd;

		while (cpy > 0)
		{
			num += 1;
			cpy /= 10;
		}

		int split = num / 2;
		int div = 10;

		while (split > 1)
		{
			div *= 10;
			split--;
		}

		int acpy = sqrd / div;
		int bcpy = sqrd % div;

		if (num % 2 != 0)
		{
			// incomplete!
		}
		else
		{

			if (bcpy != 0)
			{
				if (acpy + bcpy == number)
				{
					cout << " kaprekar number :: " << number << endl;
				}
			}
		}
	}
}