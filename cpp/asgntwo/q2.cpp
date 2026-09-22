#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int input;
	cout << "[input]:: enter number of palindrones: ";
	cin >> input;

	if (input <= 0) {
		cout << "[err]: invalid number of rows" << endl;
		return 1;
	}

	for (int i = 1; i <= input; i++) {
		for (int j = 0; j < input - i; j++) {
			cout << "  ";
		}

		for (int k = 1; k < i; k++) {
			cout << k << " ";
		}

		for (int l = i; l > 0; l--) {
			cout << l << " ";
		}

		cout << endl;
	}
}