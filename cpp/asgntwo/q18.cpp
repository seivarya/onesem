#include <iostream>
using namespace std;

int main(void)
{
	int N{0};
	cout << "[input]: ";
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int properties = 0;
		int copy = i;
		int reverse = 0;

		while (copy > 0)
		{
			int digit = copy % 10;
			reverse = reverse * 10 + digit;
			copy /= 10;
		}
		int orrev = reverse + i;
		int divisors = 0;
		int perfect = 0;
		for (int j = 1; j <= orrev; j++)
		{
			if (orrev % j == 0)
			{
				divisors++;
				if (j != orrev)
				{
					perfect += j;
				}
			}
		}
		if (perfect == orrev)
		{
			cout << "perfect!" << endl;
			properties++;
		}
		if (divisors == 2)
		{
			cout << "priime!" << endl;
			properties++;
		}
		if (reverse == i)
		{
			cout << "palin!" << endl;
			properties++;
		}
		if (properties == 2)
		{
			cout << "[found]:: " << i << endl;
		}
	}
}