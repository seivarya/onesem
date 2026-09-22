#include <iostream>
using namespace std;

int main(void) {
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
	int psmalli = 0, psmallj = 0;
	int pbigi = 0, pbigj = 0;

	int sum = 0;
	int found = 0;
	for (int i = L; i <= R - 2; i++) {
		int j = i + 2;
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
			if (found == 0) {
				psmalli = i;
				psmallj = j;
				found = 1;
			}

			pbigi = i;
			pbigj = j;

			pairs++;
			sum += i;
			sum += j;
		}
	}

	if (pairs == 0) {
		cout << "[err]: no twin prime pairs found" << endl;
		return 1;
	}

	cout << "[smallest pair]: " << "(" << psmalli << ", " << psmallj << ")" << endl;
	cout << "[largest pair]: " << "(" << pbigi << ", " << pbigj << ")" << endl;
	return 0;
}
