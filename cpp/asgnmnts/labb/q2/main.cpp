#include <iostream>
#include <string>

class Biller
{
public:
	std::string name;
	char premium; // Y or N
	float order_amount;
	float distance;
	float discount;
	float delcharge = 0;

	bool input()
	{
		std::cout << "[input]::[name]: ";
		std::getline(std::cin, name);

		std::cout << "[input]::[premium] (type Y or N): ";
		std::cin >> premium;

		if (is_valid(premium))
			return false;

		std::cout << "[input]::[food order amount]: ";
		std::cin >> order_amount;

		if (order_amount < 200)
		{
			std::cout << "[err]: MINIMUM ORDER NOT " << std::endl;
			return false;
		}

		std::cout << "[input]::[distance]: ";
		std::cin >> distance;

		return true;
	}

	void process()
	{
		process_discount();
		process_delcharge();
		if (premium == 'N')
		{
			display(false);
			return;
		}
		delcharge = delcharge - (delcharge * (50.0f / 100.0f));
		display(true);
	}

	void display(bool is_premium)
	{
		std::cout << "[ bill ]";

		if (is_premium)
			std::cout << "[]";
		else
			std::cout << "[]";
	}

	void process_discount()
	{
		if (order_amount < 500)
			discount = 0;
		else if (order_amount >= 500 && order_amount <= 999)
			discount = 5;
		else if (order_amount >= 1000 && order_amount <= 1999)
			discount = 10;
		else
			discount = 15;
		order_amount = order_amount - (order_amount * (discount / 100.0f));
	}

	void process_delcharge()
	{
		// info: calculating delievery charge
		for (int i = 1; i <= distance; i++)
		{
			if (i <= 3)
				delcharge += 40;
			else
				delcharge += 12;
		}
	}

	bool is_valid(char arg)
	{
		if (arg == 'Y' || arg == 'N')
			return true;
		return false;
	}
};

int main(void)
{
	while (1)
	{
		Biller obj;

		if (obj.input())
			obj.process();

		int status;

		std::cout << "[input]: do you wish to process another customer? [0 or 1]: ";
		std::cin >> status;

		if (status == 0)
			continue;
		else
			std::cout << "[thankyou]" << std::endl;
		break;
	}

	return 0;
}