#include <iostream>
using namespace std;

void validate_package(int *package, int *total);
void input_services(int *total);
void process_discount(int *total);
int main(void)
{

	while (1)
	{
		int total = 0;
		string name;
		int package;

		cout << "[input] :: enter username ";
		getline(cin, name);

		cout << endl;
		cout << endl;

		cout << "[1] :: basic wash" << endl;
		cout << "[2] :: premium " << endl;
		cout << "[3] :: interior + exterior " << endl;
		cout << "[4] :: full detailing " << endl;

		cout << "[input] :: choose package ";
		cin >> package;

		validate_package(&package, &total);
		input_services(&total);
		process_discount(&total);

		cout << "val ::" << total << endl;

		int status;
		cout << "[continue: 0 | exit: 1]  ";
		cin >> status;
		cin.ignore();
		if (status == 1)
		{
			break;
		}
	}
}

void process_discount(int *total)
{
	if (*total < 500)
	{
		return;
	}
	else if (*total > 500 && *total <= 999)
	{
		*total = *total - (*total * 5 / 100);
	}
	else if (*total > 1000)
	{
		*total = *total - (*total * 10 / 100);
	}
	else
	{
		return;
	}
}

void input_services(int *total)
{
	int w = 0;
	int t = 0;
	int e = 0;

	while (1)
	{
		cout << "[1] :: waxing (150) " << endl;
		cout << "[2] :: tire polishing (100) " << endl;
		cout << "[3] :: engine cleaning (250) " << endl;
		cout << "[0] :: done " << endl;

		int var;
		cout << "[select] :: option > ";
		cin >> var;
		if (var == 1)
		{
			if (w == 0)
			{
				*total += 150;
				w = 1;
			}
		}
		else if (var == 2)
		{
			if (t == 0)
			{
				*total += 100;
				t = 1;
			}
		}
		else if (var == 3)
		{
			if (e == 0)
			{
				*total += 250;
				e = 1;
			}
		}
		else if (var == 0)
		{
			break;
		}
		else
		{
			cout << "[invalid choice!] :: enter right! ";
		}
	}
}
void validate_package(int *package, int *total)
{
	if (*package == 1)
	{
		*total += 250;
	}
	else if (*package == 2)
	{
		*total += 450;
	}
	else if (*package == 3)
	{
		*total += 750;
	}
	else if (*package == 4)
	{
		*total += 1200;
	}
	else
	{
		cout << "[error]::[incorrect package entered]" << endl;
		exit(2);
	}
}
