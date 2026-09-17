#include <iostream>
using namespace std;

int main(void)
{
	string type;
	int duration;

	cout << "[input]: enter type: ";
	getline(cin, type);

	cout << "[input]: enter duration: ";
	cin >> duration;

	int cpy = duration;
	int counter = 1;
	int first_two = 0;
	int additional = 0;

	if (type == "car")
	{
		first_two = 40;
		additional = 20;
	}
	else if (type == "bike")
	{
		first_two = 20;
		additional = 10;
	}
	else if (type == "auto")
	{
		first_two = 30;
		additional = 15;
	}
	else
	{
		cout << "[err]: invalid vehicle type!" << endl;
		exit(2);
	}

	int charge = 0;

	while (cpy != 0)
	{
		if (counter <= 2)
		{
			charge = 40;
			counter++;
		}
		else
		{
			charge += 20;
		}
		cpy--;
	}

	cout << endl;
	cout << "[output]: parking bill details" << endl;
	cout << "[vehicle type]: " << type << endl;
	cout << "[duration]: " << duration << endl;
	cout << "[first two hours charge]: " << first_two << endl;
	cout << "[additional hour charge]: " << additional << endl;
	cout << "[total charge]: " << charge << endl;
}
