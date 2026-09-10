#include <iostream>
#include <string>

unsigned int SERVICE_CHARGE = 50;

class Consumer {

	std::string name;
	unsigned long int phone;
	double units;
	double charge;

	public:

	void input() { 
		//  note: instead of one .input() method, we can make separate methods
		//  for each of the variables asw
		std::cout << "[name]: ";
		std::getline(std::cin >> std::ws, name);

		std::cout << "[phone]: ";
		std::cin >> phone;

		std::cout << "[units]: ";
		std::cin >> units;

		charge = calc();
	}

	double calc() {
		double tmp { 0 };
		double cost { 0 };

		while (tmp < units) {
			
			if (tmp <= 100)
				cost +=  2;
			if (tmp > 100 && tmp <= 200)
				cost += 3.50;
			if (tmp > 200 && tmp <= 500)
				cost += 5;
			if (tmp > 500)
				cost += 7.50;
			tmp++;
		}
		// std::cout << "[debug]: "<< cost << std::endl;
		return cost;
	}

	void display() {
		std::cout << std::endl;
		std::cout << "[bill]" << std::endl << std::endl;
		std::cout << "[customer name] > " << name << std::endl;
		std::cout << "[customer mobile] > " << phone<< std::endl;
		std::cout << "[units consumed] > " << units << std::endl;
		std::cout << "[units charge] > " << calc() << std::endl;
		std::cout << "[service fee] > " << SERVICE_CHARGE << std::endl << std::endl;
		std::cout << "[total charge] > " <<  calc() + SERVICE_CHARGE << std::endl;
		std::cout << std::endl;
	}
};

int main(void) {
	Consumer c;
	c.input();
	c.display();
}
