#include <iostream>
#include <string>

class Vehicle {
	public:
		std::string owner;
		std::string registration;
		std::string type;

		double duration;

		void input() {
			std::cout << "[welcome]" << std::endl;
			std::cout << "[input]: enter your name: ";
			std::getline(std::cin >> std::ws, owner);

			std::cout << "[input]: enter your registration number: ";

			std::getline(std::cin >> std::ws, registration);

			std::cout << "[input]: enter your vehicle type: ";
			std::getline(std::cin >> std::ws, type);

			std::cout << "[input]: enter the duration of your stay!";
			std::cin >> duration;
		}

		double charges() {
			double charge;
			double temp = duration - 2;

			if (type == "car" || type == "Car") {
				charge = 40;
				while (temp > 0) {
					charge += 20;
					temp--;
				}

			} else if (type == "bike" || type == "Bike") {
				charge = 20;

				while (temp >= 0) {
					charge += 10;
					temp--;
				}
			} else { // info: 15 | 05 for unknown vehicle
				charge = 15;
				while (temp >= 0) {
					charge += 5;
					temp--;
				} 
			}
			return charge;
		}
		bool validate_name() {

		}

		bool validate_registration() {

		}

		bool validate_type() {

		}

		bool validate_duration() {

		}

		bool is_reg_valid(std::string reg) {

		}


};

class Slot {
	public:
		Vehicle vehicle;
		bool occupied = false; 
		bool is_occupied() {
			return occupied;
		}

};

class Parking {
	public:
		Slot slots[50];

		void park(Vehicle vehicle) {
			std::cout << "[exec]: parking vehicle" << std::endl;
			for (int i = 0; i < 50; i++) {
				if (!(slots[i].is_occupied())) {
					slots[i].vehicle = vehicle;
					slots[i].occupied = true;
					return; 
				}

			}
			std::cout << "[uh oh] :: there are no slots left for parking!!" << std::endl;
		}

		void remove(int slot) {
			if (slot < 1 || slot > 50) { std::cout << "[error]: ????" << std::endl; return; }
			std::cout << "[exec]: removing vehicle from [slot] :: " << slot << std::endl;

			slots[slot - 1].occupied = false;
		}

		void search(std::string registration) { // can be searched via name + reg asw
			for (int i = 0; i < 50; i++) {
				if (slots[i].is_occupied()) {
					if (slots[i].vehicle.registration == registration) {
						std::cout << "[info] :: [vehicle found] :: [data] :: [owned by] ::  " << slots[i].vehicle.owner << std::endl;
						return;
					}
				}
			}
			std::cout << "[failed] :: couldn't find a vehicle with reg no. :: " << registration << std::endl;

		}

		void display_slots() {
			std::cout << "[exec]: displaying slots" << std::endl;

			for (int i = 0; i < 50; i++) {
				std::cout << "[info] :: [slot number] :: " << i + 1 << std::endl;
				if (slots[i].is_occupied()) {
					std::cout << "[info] :: [occuppied] :: [owner] :: " << slots[i].vehicle.owner << std::endl;
					return;
				}
				std::cout << "[info] :: [unoccuppied]" << std::endl;
			}
		}

		void charges(std::string registration) {

		}
};

// todo:
// duplicate checks of reg. number.
// string validation
// cleaned up methods
// inloop sys
// ...

int main() {
	Parking parking;

	Vehicle vehicle;
	vehicle.input();

	parking.park(vehicle);
}

