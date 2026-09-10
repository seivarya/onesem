#include <bits/stdc++.h>
using namespace std;
class Solution {
	public:
	string modifyString(string str) {
		string newStr = str;
		newStr[0] = 'X';
		return newStr;
	}
};

int main(void) {
	string org = "xenon";
	Solution sol;
	string modif = sol.modifyString(org);

	cout << org << endl;
	cout << modif << endl;
}