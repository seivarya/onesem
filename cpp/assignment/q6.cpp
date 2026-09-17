#include <iostream>

using namespace std;

int main(void)
{

	int left;
	int right;
	cout << "[input]: ";
	cint >> left >> right;

	int number = 1;

	int n1 = 2, n2 = 3;
	int max = 2;

	while (number != right)
	{
		int divisors = 0;
		for (int div = 1; div <= number; div++)
		{
			if (number % div == 0)
			{
				divisors++;
			}
		}
		if (divisors == 2)
		{
			n1 = n2;
			n2 = number;
		}
		if (n2 - n1 > max)
		{
			max = n2 - n1;
		}
		number++;
	}

	cout << n1 << " :: " << n2 << endl; // bug!
	cout << max << endl;
}