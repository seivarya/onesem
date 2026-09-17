#include <iostream>

#define REC_DAILY_CONSUMPTION 125

class Apartment
{
public:
	int number;
	int residents;
	float max_consumption;
	float total_consumed;
	int open;
	int close;

	void input()
	{

		std::cout << "enter apartment number: ";
		std::cin >> number;

		std::cout << "enter total residents: ";
		std::cin >> residents;

		std::cout << "enter the open water line reading: ";
		std::cin >> open;

		std::cout << "enter the closing water line reading: ";
		std::cin >> close;

		if (open > close)
		{
			std::cout << "[err]: open line reading cannot be greater than closing! exiting...";
			exit(2);
		}

		max_consumption = residents * REC_DAILY_CONSUMPTION;
		total_consumed = close - open;
		;
	}

	void status()
	{
		if (total_consumed <= max_consumption)
		{
			std::cout << "[status]: WITHIN LIMIT" << std::endl;
			if (total_consumed == max_consumption)
			{
				std::cout << "[the consumption is exactly equal!]: " << std::endl;
				return;
			}
			float deficit = ((max_consumption - total_consumed) / max_consumption) * 100;
			std::cout << "[deficit]: " << deficit << std::endl;
		}
		else
		{
			float excess = ((total_consumed - max_consumption) / max_consumption) * 100;
			if (excess <= 20)
			{
				std::cout << "[status]: MODERATE" << excess << std::endl;
			}
			else
			{
				std::cout << "[status]: HIGH CONSUMPTION " << excess << std::endl;
			}
		}
	}

	void display()
	{

	}
};

int main(void)
{
	while (1)
	{
		Apartment obj;

		obj.input();
		obj.status();
		obj.display();

		int status;
		std::cout << "[input]: do you wish to process another apartment? [0 or 1]: ";
		std::cin >> status;
		if (status == 0)
		{
			continue;
		}
		else
		{
			std::cout << "[thankyou]" << std::endl;
			break;
		}
	}
	return 0;
}