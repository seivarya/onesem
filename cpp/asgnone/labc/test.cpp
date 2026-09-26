#include <iostream>

int main(void)
{
	double final_price;
	double price = 2100;
	double discount = 3;
	final_price = price - ((discount / 100) * price);
	std::cout << final_price;
}