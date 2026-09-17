#include <iostream>
using namespace std;

int main(void)
{
	string name;
	float hour_wage;
	float hours_worked;

	cout << "[input]: enter name: ";
	getline(cin, name);

	cout << "[input]: enter hourly wage: ";
	cin >> hour_wage;

	cout << "[input]: enter total hours worked: ";
	cin >> hours_worked;

	if (hour_wage <= 0 || hours_worked <= 0)
	{
		cout << "[err]: wage / hours cannot be negative or zero!" << endl;
		exit(3);
	}

	int salary = 0;
	int cpy = hours_worked;

	while (cpy != 0)
	{
		if (hours_worked <= 40)
		{
			salary += hour_wage;
		}
		else
		{
			salary += (1.5 * hour_wage);
		}
		cpy--;
	}

	cout << endl;
	cout << "[output]: salary details" << endl;
	cout << "[name]: " << name << endl;
	cout << "[hourly wage]: " << hour_wage << endl;
	cout << "[hours worked]: " << hours_worked << endl;
	cout << "[salary]: " << salary << endl;

	if (salary > 10000)
	{
		cout << "[earner type]: high earner" << endl;
	}
	else
	{
		cout << "[earner type]: regular earner" << endl;
	}
}