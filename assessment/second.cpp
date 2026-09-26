#include <iostream>
using namespace std;

const unsigned int PLAN_199 = 199;
const unsigned int PLAN_399 = 399;
const unsigned int PLAN_699 = 699;
const unsigned int PLAN_999 = 999;

double recharge = 0;
double cashback = 0;

bool select_plan(unsigned int plan)
{
	if (plan == PLAN_199 ||
	    plan == PLAN_399 ||
	    plan == PLAN_699 ||
	    plan == PLAN_999)
	{
		recharge = plan;
		return true;
	}

	return false;
}

void calculate_cashback()
{
	double percentage = 0;

	if (recharge == PLAN_199)
	{
		percentage = 0;
	}
	else if (recharge == PLAN_399)
	{
		percentage = 5;
	}
	else if (recharge == PLAN_699)
	{
		percentage = 10;
	}
	else if (recharge == PLAN_999)
	{
		percentage = 15;
	}

	cashback = (recharge * percentage) / 100;

	if (recharge > 700)
	{
		cashback = cashback + 50;
	}

	if (cashback > 200)
	{
		cashback = 200;
	}
}

void display(unsigned long long int mobile)
{
	double net_value = recharge - cashback;

	cout << "[===== [receipt] =====]" << endl
	     << endl;

	cout << "[mobile] :: [" << mobile << "]" << endl;
	cout << "[recharge] :: [Rs " << recharge << "]" << endl;
	cout << "[cashback] :: [Rs " << cashback << "]" << endl;
	cout << "[net value] :: [Rs " << net_value << "]" << endl;
}

int main()
{
	unsigned int plan;
	unsigned long long int mobile;

	int status = 1;
	int successful_recharges = 0;
	double total_cashback = 0;

	while (status == 1)
	{
		recharge = 0;
		cashback = 0;

		int num{0};
		cout << "[input] :: [enter mobile number] :: ";
		cin >> mobile;

		cout << "[input] :: [enter plan] :: ";
		cin >> plan;

		if (!select_plan(plan))
		{
			cout << "[err]: invalid plan! Recharge rejected."
			     << endl;
		}
		else
		{
			calculate_cashback();
			display(mobile);

			successful_recharges++;
			total_cashback = total_cashback + cashback;
		}

		cout << endl;

		cout << "[do you wish to continue??\n"
		     << "  yes: 1 | no: 0] ";
		cin >> status;

		cout << endl;
	}

	cout << "[===== [summary] =====]" << endl
	     << endl;

	cout << "[total cashback] :: [rs. " << total_cashback << "]" << endl;

	return 0;
}
