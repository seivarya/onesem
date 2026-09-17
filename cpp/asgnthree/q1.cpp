#include <iostream>

float FIXED_MAINTENANCE_CHARGE = 30;

class calci
{
public:
	std::string name;
	float consumption;
	float ucharge;

	void input()
	{
		std::cout << "[input]: enter household name :: ";
		std::getline(std::cin, name);

		std::cout << "[input]: enter water consumption :: ";
		std::cin >> consumption;

		if (consumption <= 0)
		{
			std::cout << "[error]: value cannot be negative / 0 :: exiting\n";
			exit(3);
		}
	}

	float calculate()
	{
		if (consumption >= 500)
			ucharge = (consumption / 100) * 3;
		else
			ucharge = (consumption / 100) * 2;

		return (ucharge + FIXED_MAINTENANCE_CHARGE);
	}

	void display()
	{
		std::cout << std::endl
			  << "[output]: water bill ::\n";
		std::cout << "[household name]: " << name << std::endl;
		std::cout << "[consumption]: " << consumption << std::endl;
		std::cout << "[maintenance charge]: " << FIXED_MAINTENANCE_CHARGE << std::endl;
		std::cout << "[total charge]: " << calculate() << std::endl;
	}
};

int main(void)
{
	calci inst = calci();
	inst.input();
	inst.display();
}
