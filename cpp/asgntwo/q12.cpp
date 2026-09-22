#include <iostream>
using namespace std;

int main() {
	int L, R;
	cout << "[input]: enter left ";
	cin >> L;

	cout << "[input]: enter right ";
	cin >> R;

	if (L <= 0 || R <= 0 || L >= R) {
		cout << "[err]: invalid range" << endl;
		return 1;
	}

	int pairs = 0;

	int psmalli = 3;
	int psmallj = 5;

	int pbigi = 3;
	int pbigj = 5;

	int sum = 0;
	int found = 0;
	for (int i = L; i < R; i++) {
		int j = i + 2;
		int icpy = i;
		int jcpy = j;
		int idivisors = 0;
		for (int k = 1; k <= i; k++) {
			if (i % k == 0) {
				idivisors++;
			}
		}
		int jdivisors = 0;
		for (int l = 1; l <= j; l++) {
			if (j % l == 0) {
				jdivisors++;
			}
		}
		if (idivisors == 2 && jdivisors == 2) {
			if ((j - i) == 2) {
				if (found == 0) {
					psmalli = i;
					psmallj = j;
					found = 1;
				}

				if (i > pbigi && j > pbigj) {
					pbigi = i;
					pbigj = j;
				}

				pairs++;
				sum += i;
				sum += j;
			}
		}
	}

	cout << "[info] :: [smallest pair] : " << "(" << psmalli << ", " << psmallj << ")" << endl;
	cout << "[info] :: [largest pair] : " << "(" << pbigi << ", " << pbigj << ")" << endl;
}
