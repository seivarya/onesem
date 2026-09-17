#include <iostream>
using namespace std;

int main(void)
{
	float sandwich{0}, burger{0}, pasta{0};

	while (1)
	{
		int input;

		cout << "[menu]: [1] sandwich" << endl;
		cout << "[menu]: [2] burger" << endl;
		cout << "[menu]: [3] pasta" << endl;
		cout << "[menu]: [4] done" << endl;
		cout << "[input]: enter choice: ";
		cin >> input;

		if (input < 1 || input > 4)
		{
			cout << "[err]: invalid choice!" << endl;
			continue;
		}

		if (input == 4)
		{
			break;
		}

		if (input == 1)
		{
			sandwich += 80;
		}
		else if (input == 2)
		{
			burger += 120;
		}
		else
		{
			pasta += 150;
		}

		cout << endl;
	}

	float total = burger + sandwich + pasta;

	float discount = (total > 500) ? (total * 0.05) : 0;
	float final_price = total - discount;

	cout << endl;

	cout << "[output]: order details" << endl;
	cout << "[sandwich total]: " << sandwich << endl;
	cout << "[burger total]: " << burger << endl;
	cout << "[pasta total]: " << pasta << endl;
	cout << "[subtotal]: " << total << endl;
	cout << "[discount]: " << discount << endl;
	cout << "[final price]: " << final_price << endl;
}
