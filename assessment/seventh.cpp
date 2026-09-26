#include <iostream>

using namespace std;

int main(void)
{
	double arr[100];
	int i = 0;
	int over = 0;
	while (1)
	{
		double weight;
		cout << "[input] :: enter weight  ";
		cin >> weight;

		if (weight < 0)
		{
			cout << "[err]: incorrect weight side" << endl;
			cin.ignore();
			continue;
		}

		if (i >= 100)
		{
			cout << "[err] can't handle much weight" << endl;
			break;
		}
		if (weight == 0)
		{
			break;
		}
		arr[i] = weight;
		i++;
	}
	int tot = 0;
	for (int j = 0; j < i; j++)
	{
		int temp = arr[j];
		if (temp <= 2)
		{
			tot += 20;
		}
		else if (temp > 2 && temp <= 10)
		{
			tot += 50;
		}
		else if (temp > 10 && temp <= 25)
		{
			tot += 100;
		}
		else if (temp > 25)
		{
			tot += 200;
			over += 1;
		}
		else
		{
			tot += 0;
		}
	}
	while (over != 0)
	{
		tot += 50;
		over--;
	}

	cout << "[final cost] :: " << tot << endl;
}
