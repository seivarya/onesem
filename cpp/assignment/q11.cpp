#include <iostream>
using namespace std;

int main(void)
{
	int input;
	cout << "[input]: ";
	cin >> input;

	for (int i = 1; i <= input; i++)
	{

		int term = 0;
		int counter = 0;
		int maxlen = 0;
		int max = 0;

		while (term != 1)
		{

			if (i % 2 == 0)
			{
				term /= 2;
			}
			else
			{
				term = (3 * term) + 1;
			}
			if (term > max)
			{
				max = term;
			}
			counter++;
		}

		if (counter > maxlen)
		{
			maxlen = counter;
		}
	}
}
