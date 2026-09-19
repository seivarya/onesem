#include <iostream>
using namespace std;

int main(void)
{
	int input;
	cout << "[input]: ";
	cin >> input;

	int seqlen = 0;
	int largest_seqlen = 0;
	int start = 0;
	int largest_val = 0;
	for (int i = 1; i <= input; i++)
	{
		int copy = i;
		int seqcount = 0;
		while (copy != 1)
		{
			cout << "[ " << copy << " ] ";
			if (copy % 2 == 0)
			{
				copy = copy / 2;
			}
			else
			{
				copy = (3 * copy) + 1;
			}
			if (copy > largest_val)
			{
				largest_val = copy;
			}
			seqcount++;
		}
		cout << endl;

		if (seqcount > largest_seqlen)
		{
			largest_seqlen = seqcount;
			start = i;
		}
	}
	cout << "[ collatz sequence ]" << endl;
	cout << " [started with ] :: " << start << endl;
	cout << " [ sequence length ] :: " << largest_seqlen << endl;
	cout << " [ largest value reached ] :: " << largest_val << endl;
}
