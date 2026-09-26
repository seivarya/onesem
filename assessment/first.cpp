#include <iostream>
#include <string>
using namespace std;

const unsigned int PETROL = 105;
const unsigned int DIESEL = 92;
const unsigned int CNG = 85;
class Customer
{
public:
	string name;
	string fuel_type;

	double quantity{0};
	double discount{0};
	double final_price{0};
	double fuel_price{0};
	bool is_loyal{false};
	double loyalty_price{0};

	void input()
	{
		cout << "[input] :: [enter customer name] :: ";
		getline(cin, name);

		cout << "[input] :: [enter fuel type in lower case only] :: ";
		getline(cin, fuel_type);

		cout << "[input] :: [enter fuel quantity] :: ";
		cin >> quantity;

		cout << endl;

		if (fuel_type == "petrol")
		{
			fuel_price = PETROL;
		}
		else if (fuel_type == "cng")
		{
			fuel_price = CNG;
		}
		else if (fuel_type == "diesel")
		{
			fuel_price = DIESEL;
		}
		else
		{
			cout << "[err]: invalid fuel type!" << endl;
			return;
		}

		validate_data();
		calculate_discount();
		apply_discount();
	}

	void validate_data()
	{
		if (name.empty())
			cout << "[err]: name not entered!" << endl;

		if (fuel_type.empty())
			cout << "[err]: fuel type not entered!" << endl;

		if (quantity <= 0)
			cout << "[err]: invalid quantity entered!" << endl;
	}

	void calculate_discount()
	{
		if (quantity <= 0)
		{
			cout << "[err]: invalid quantity!" << endl;
			return;
		}

		if (quantity < 10)
		{
			discount = 0.0;
		}
		else if (quantity <= 30)
		{
			discount = 3.0;
		}
		else if (quantity <= 50)
		{
			discount = 5.0;
		}
		else
		{
			discount = 5.0;
			is_loyal = true;
		}
	}

	void apply_discount()
	{
		double price = fuel_price * quantity;
		loyalty_price = (is_loyal) ? 100 : 0;
		final_price = price - ((discount / 100) * price) - loyalty_price;
	}

	void display()
	{
		cout << "[===== [bill] =====]" << endl
		     << endl;

		cout << "[name] :: [" << name << "]" << endl;
		cout << "[fuel] :: [" << fuel_type << "]" << endl;
		cout << "[quantity] :: [" << quantity << "]" << endl;
		cout << "[base] :: [" << fuel_price * quantity << "]" << endl;
		cout << "[loyalty price] :: [" << loyalty_price << "]" << endl;

		cout << "[discount] :: ["
		     << (discount / 100) * (fuel_price * quantity)
		     << "]" << endl
		     << endl;

		cout << "[final] :: [" << final_price << "]" << endl;
	}
};

int main()
{
	int status = 0;
	while (1)
	{
		Customer inst;
		inst.input();
		inst.display();
		cout << "[do you wish to continue??\n  yes: 1 | no: 0] ";
		cin >> status;
		if (status == 0)
		{
			break;
		}
		cin.ignore();
		cout << endl;
	}
	return 0;
}
