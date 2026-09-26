#include <iostream>
#include <string>
using namespace std;

int extract_hour(string);
int extract_minute(string);
int calculate_hrs(int, int, int, int);
int calculate_charge(int);

int main(void)
{
	long long int regno;

	string entry_time;
	string exit_time;

	cout << "[input]: enter regno :: ";
	cin >> regno;

	cout << "[input]: entry time :: ";
	cin >> entry_time;

	cout << "[input]: exit time :: ";
	cin >> exit_time;

	int entry_hour = extract_hour(entry_time);
	int entry_min = extract_minute(entry_time);

	int exit_hour = extract_hour(exit_time);
	int exit_min = extract_minute(exit_time);

	int hrs = (int)(calculate_hrs(entry_hour, entry_min, exit_hour, exit_min) / 60);
	if (hrs < 0)
	{
		cout << "[err]: only valid for 24 hours!" << endl;
	}
	else
	{

		cout << "[output]: duration :: " << hrs << " hours" << endl;
		cout << "[output]: charge :: " << calculate_charge(hrs) << " rupees" << endl;
	}

	return 0;
}

int calculate_charge(int hrs)
{
	int tmp{1};
	int charge = 0;
	while (tmp <= hrs)
	{
		if (tmp == 1)
		{
			charge += 30;
		}
		else if (tmp == 2 || tmp == 3)
		{
			charge += 20;
		}
		else if (tmp >= 3)
		{
			charge += 15;
		}
		else
		{
			charge += 0;
		}
		tmp++;
	}
	if (hrs > 8)
	{
		charge += 50;
	}
	return charge;
}

int extract_hour(string time)
{
	string sbstr = time.substr(0, 2); // stoi
	if (sbstr[0] == '0')
	{
		sbstr[0] = ' ';
	}
	return stoi(sbstr);
}

int extract_minute(string time)
{
	string sbstr = time.substr(0, 2);
	if (sbstr[0] == '0')
	{
		sbstr[0] = ' ';
	}
	return stoi(sbstr);
}

int calculate_hrs(int entry_hour, int entry_min,
		  int exit_hour, int exit_min)
{
	int entry_total = entry_hour * 60 + entry_min;
	int exit_total = exit_hour * 60 + exit_min;

	return exit_total - entry_total;
}
