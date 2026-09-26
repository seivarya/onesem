#include <iostream>

using namespace std;

const int WALKING = 5;
const int RUNNING = 10;
const int CYCLING = 8;
const int SWIMMING = 12;

int validate_type(string type)
{
	if (type == "walking" || type == "cycling" ||
	    type == "running" || type == "swimming")
	{
		return 1;
	}
	return 0;
}

double calculate_calories(string type, double duration)
{
	if (type == "walking")
	{
		return WALKING * duration;
	}
	else if (type == "running")
	{
		return RUNNING * duration;
	}
	else if (type == "cycling")
	{
		return CYCLING * duration;
	}
	else if (type == "swimming")
	{
		return SWIMMING * duration;
	}

	return 0;
}

string classify(double calories)
{
	if (calories < 200)
	{
		return "LOW";
	}
	else if (calories < 500)
	{
		return "MODERATE";
	}
	else if (calories < 800)
	{
		return "HIGH";
	}
	else
	{
		return "INTENSE";
	}
}

int main(void)
{
	string name;

	int sessions;
	double duration;

	cout << "[input]: enter name ";
	cin >> name;

	cout << "[input]: sessions ";
	cin >> sessions;

	string type[sessions];
	double calories[sessions];

	double total = 0;
	double maximum = 0;

	int max_session = 0;

	for (int i = 0; i < sessions; i++)
	{
		string val;

		cout << "[input] :: [exercise type] :: ";
		cin >> val;

		if (validate_type(val))
		{
			type[i] = val;

			cout << "[input] :: [duration] :: ";
			cin >> duration;

			if (duration < 0)
			{
				cout << "[err]: duration cannot be negative" << endl;
				calories[i] = 0;
				continue;
			}

			calories[i] = calculate_calories(type[i], duration);

			total = total + calories[i];

			if (calories[i] > maximum)
			{
				maximum = calories[i];
				max_session = i;
			}
		}
		else
		{
			cout << "[err]: enter valid value" << endl;

			calories[i] = 0;
			continue;
		}
	}

	double average = 0;

	if (sessions > 0)
	{
		average = total / sessions;
	}

	cout << endl;
	cout << "[output] :: member :: " << name << endl;

	cout << "[output] :: sessions" << endl;

	for (int i = 0; i < sessions; i++)
	{
		if (calories[i] > 0)
		{
			cout << i + 1 << ": "
			     << type[i] << " :: "
			     << calories[i] << " calories" << endl;
		}
	}

	cout << "[output] :: total calories :: "
	     << total << endl;

	cout << "[output] :: average calories :: "
	     << average << endl;

	cout << "[output] :: maximum calories :: "
	     << maximum << endl;

	cout << "[output] :: maximum session :: "
	     << max_session + 1 << endl;

	cout << "[output] :: activity level :: "
	     << classify(total) << endl;

	return 0;
}
