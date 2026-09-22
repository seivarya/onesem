#include <iostream>
using namespace std;

int main(void) {

	int oned;
	int twod = 3324891;
	cout << "[input] :: ";
	cin >> oned;
	cout << "[input] :: ";
	cin >> twod;

	if (oned <= 0 || twod <= 0) {
		cout << "[err]: invalid input" << endl;
		return 1;
	}

	int xsorted = 0;
	int xcounter = 0;
	for (int i = 0; i <= 9; i++) {
		int xtmp = oned;
		while (xtmp > 0) {
			int oned = xtmp % 10;
			if (i == oned) {
				xsorted = xsorted * 10 + oned;
				xcounter++;
			}
			xtmp /= 10;
		}
	}

	int ysorted = 0;
	int ycounter = 0;
	for (int i = 0; i <= 9; i++) {
		int ytmp = twod;
		while (ytmp > 0) {
			int digit = ytmp % 10;
			if (digit == i) {
				ysorted = ysorted * 10 + digit;
				ycounter++;
			}
			ytmp /= 10;
		}
	}
	if (xcounter != ycounter) {
		cout << "[info] :: [not anagrams!]" << endl;
		return 1;
	}
	int xcpy = xsorted;
	int ycpy = ysorted;

	while (xcpy > 0) {
		int i = xcpy % 10;
		int j = ycpy % 10;
		if (i != j) {
			cout << "[info] :: [not anagrams!]" << endl;
			return 1;
		}
		xcpy /= 10;
		ycpy /= 10;
	}
	cout << "[info] :: [anagram digits!]" << endl;
}
