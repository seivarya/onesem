#include <iostream>
using namespace std;

int main(void)
{
	int N{0};
	cout << "[input]: ";
	cin >> N;

	int total = 0;
	int largest = 0;
	int smallest = 0;
	int sum = 0;
	int temp = 0;

	int max_row = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int M = i * j;
			int properties = 0;

			if (properties >= 2)
			{
				cout << "[number] :: " << M << endl;

				if (temp = 0)
				{
					smallest = M;
					temp = 1;
				}
				if (M > largest)
				{
					largest = M;
				}
				sum += M;
				total++;
			}
		}
	}
	cout << "[total number of such values]: " << total << endl;
	cout << "[largest]: " << largest << endl;
	cout << "[smallest]: " << smallest << endl;
	cout << "[sum]: " << sum << endl;
}