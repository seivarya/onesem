#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int input = 5;
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
				// cout << i << "::" << j << endl;
				max_main = i * j;
			}
			if (i == 2 && j == 1) {
				min_main = i * j;
			}
		}
		cout << endl;
	}
	cout << "[info] :: [sum of main diagonal] : " << main_diagonal << endl;
	cout << "[info] :: [sum of secondary diagonal] : " << side_diagonal << endl;
	cout << "[info] :: [largest element above main diagonal] : " << max_main << endl;
	cout << "[info] :: [smallest element below main diagonal] : " << min_main << endl;
}