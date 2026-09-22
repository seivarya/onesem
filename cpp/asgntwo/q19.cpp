#include <iostream>
using namespace std;

int main(void)
{
	int input;
	cout << "[input]: ";
	cin >> input;

	if (input <= 0)
	{
		cout << "[err]: invalid input" << endl;
		return 1;
	}

	return 0;
}
