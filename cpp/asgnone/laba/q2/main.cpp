#include <iostream>
#include <string>

class Patient {

	public:
		std::string name;
		float temperature;
		int heart_rate;

		void input() {
			std::cout << "[input]: enter patient's name > ";
			std::getline(std::cin >> std::ws, name);

			std::cout << "[input]: enter patient's temperature > ";
			std::cin >> temperature;

			std::cout << "[input]: enter patient's heart beat > ";
			std::cin >> heart_rate;
		}

		std::string fetch_temp() {
			if (temperature >= 36 && temperature <= 37.5) {
				return "[status]: normal";
			} else if (temperature < 36) {
				return "[status]: low temperature!";
			} else {
				return "[status]: fever";
			}
		}

		std::string fetch_heart() {
			if (heart_rate >= 60 && heart_rate <= 100) {
				return "[status]: normal";
			} else if (heart_rate < 60) {
				return "[status]: low heart rate";
			} else {
				return "[status]: high heart rate";
			}
		}

		void display() {
			std::cout << "[patient name]: > " << name << std::endl;
			std::cout << "[patient temp]: > " << temperature << std::endl;
			std::cout << fetch_temp() << std::endl;
			std::cout << fetch_heart() << std::endl;
			std::cout << std::endl;
		}

};

int main(void) {
	while (1) {
		Patient p;
		p.input();
		p.display();
	}
}
