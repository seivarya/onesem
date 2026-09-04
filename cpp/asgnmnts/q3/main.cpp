#include <iostream>

class Student {

	std::string name;
	std::string enroll;
	std::string grade;

	int age;
	int marks[6];
	int highest;
	int lowest;
	int total_marks = 0;
	float percentage;

	public:

	void input() {
		std::cout << "[input]: student name >> ";
		std::getline(std::cin >> std::ws, name);

		std::cout << "[input]: roll number >> ";
		std::getline(std::cin >> std::ws, enroll);

		std::cout << "[input]: age >> ";
		std::cin >> age;

		std::cout << std::endl;

		for (int i = 0; i < 6; i++) {
			std::cout << "[input] enter subject " << i + 1 << " >> ";
			std::cin >> marks[i];

			total_marks += marks[i]; // saves iter.
		}

		calc_grade();
		highlow();
	}

	bool is_passed() {
		for (int i = 0; i < 6; i++) {
			if (marks[i] < 40) {
				return false;
			}
		}

		return true;
	}

	void calc_grade() {
		percentage = ((float)total_marks / 600) * 100;

		if (is_passed() == false) {
			grade = "f";
			return;
		}

		if (percentage >= 90) {
			grade = "a+";
		} else if (percentage >= 80 && percentage <= 89) {
			grade = "a";
		} else if (percentage >= 70 && percentage <= 79) {
			grade = "b";
		} else if (percentage >= 60 && percentage <= 69) {
			grade = "c";
		} else if (percentage >= 50 && percentage <= 59) {
			grade = "d";
		} else {
			grade = "f";
		}
	}

	void highlow() {
		highest = marks[0];
		lowest = marks[0];

		for (int i = 0; i < 6; i++) {
			if (marks[i] > highest) {
				highest = marks[i];
			}

			if (marks[i] < lowest) {
				lowest = marks[i];
			}
		}
	}

	void display() {
		std::cout << "\n";
		std::cout << "[student data]\n";

		std::cout << "[name]        :: " << name << '\n';
		std::cout << "[roll number] :: " << enroll << '\n';
		std::cout << "[age]         :: " << age << '\n';

		std::cout << "\n";
		std::cout << "[marks]\n";

		for (int i = 0; i < 6; i++) {
			std::cout << "[subject " << i << "]  :: " << marks[i] << '\n';
		}

		std::cout << "[total marks] :: " << total_marks << " / 600\n";
		std::cout << "[percentage]  :: " << percentage << "%\n";
		std::cout << "[highest]     :: " << highest << '\n';
		std::cout << "[lowest]      :: " << lowest << '\n';
		std::cout << "[result]      :: "
			<< (is_passed() ? "passed" : "failed") << '\n';
		std::cout << "[grade]       :: " << grade << '\n';
	}
};

int main(void) {
	Student s;

	s.input();
	s.display();
}
