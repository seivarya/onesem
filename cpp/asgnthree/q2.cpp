#include <iostream>
using namespace std;

int main(void)
{
	string name;
	float usage;

	cout << "[input]: enter name: ";
	getline(cin, name);

	cout << "[input]: enter usage: ";
	cin >> usage;

	if (usage < 0)
	{
		cout << "[err]: can't be negative!" << endl;
		exit(2);
	}

	int additional = 0;
	if (usage > 10)
		additional += 100;

	int charge = 0;
	if (usage <= 2)
	{
		charge = 100;
	}
	else if (usage <= 5)
	{
		charge = 200;
	}
	else if (usage > 5)
	{
		charge = 350;
	}
	else
	{
		cout << "[err]: invalid usage value!" << endl;
	}

	cout << endl;
	cout << "[output]: bill details" << endl;
	cout << "[name]: " << name << endl;
	cout << "[usage]: " << usage << endl;
	cout << "[base charge]: " << charge << endl;
	cout << "[additional charge]: " << additional << endl;
	cout << "[total charge]: " << charge + additional << endl;
}
