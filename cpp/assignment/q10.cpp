#include <iostream>
using namespace std;
int main(void)
{
	int input = 2020;
	// cout << "[input]: ";
	// cin >> input;
	int digits = 0;
	int copy = input;
	while (copy > 0)
	{
		digits++;
		copy /= 10;
	}
	cout << digits << endl;
	int div = 1;
	while (digits > 1)
	{
		div *= 10;
		digits--;
	}
	cout << div << endl;

	int bcopy = input;
	for (int i = 0; i < digits; i++)
	{
		int counter = 0;
		int num = bcopy / div;
		int ccopy = input;
		while (ccopy > 0)
		{
			int temp = ccopy % 10;
			if (temp == num)
			{
				counter++;
			}
			ccopy /= 10;
		}
		if (i != counter)
		{
			cout << "not self descriptive!" << endl;
		}
		bcopy %= div;
		div /= 10;
	}
}