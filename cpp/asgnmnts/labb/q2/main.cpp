#include <iostream>
#include <string>

class Biller {
	public:
		float order_amount;
		float delivery_distance;
		char is_premium_member;

		float delivery_fee;
		float order_fee;
		float total_fee;

		bool input() {
			std::cout << "[input]:: enter order amount: ";
			std::cin >> order_amount;

			std::cout << "[input]:: enter delivery distance: ";
			std::cin >> delivery_distance;

			std::cout << "[input]:: is premium member (Y for yes, N for no): ";
			std::cin >> is_premium_member;

			if (order_amount < 0 || delivery_distance < 0 || (is_premium_member != 'Y' && is_premium_member != 'N')) {
				std::cout << "[error]:: invalid input" << std::endl;
				return false;
			}
			return true;
		}

};

int main(void) {
	while(1) {
		Biller biller;

		char choice;
		std::cout << "[prompt]: do you wish to process another customer (Y or N): ";
		std::cin >> choice;

		if (choice == 'N') {
			std::cout << "[info]:: exiting program" << std::endl;
			break;
		} else if (choice != 'Y') {
			std::cout << "[error]:: invalid choice" << std::endl;
			continue;
		}
	}
	std::cout << "thanks" << std::endl;
	return 0;
}