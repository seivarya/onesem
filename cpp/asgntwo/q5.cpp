#include <iostream>

using namespace std;

int main(void) {
	int input;
	cout << "[input]: ";
	cin >> input;

	if (input <= 0) {
		cout << "[err]: invalid matrix size" << endl;
		return 1;
	}

	int main_diagonal = 0;
	int side_diagonal = 0;

	int max_main = 0;
	int min_main = 0;

	for (int i = 1; i <= input; i++) {
		for (int j = 1; j <= input; j++) {
			cout << i * j << " ";
			if (i == j) {
				main_diagonal += (i * j);
			}
			if (j == input - i + 1) {
				side_diagonal += (i * j);
			}
			if (i == input - 1 && j == input) {
				max_main = i * j;
			}
			if (i == 2 && j == 1) {
				min_main = i * j;
			}
		}
		cout << endl;
	}
	cout << main_diagonal << endl;
	cout << side_diagonal << endl;
	cout << max_main << endl;
	cout << min_main << endl;
	return 0;
}