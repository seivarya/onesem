#include <iostream>
using namespace std;

int main(void) {
    int input;
    cout << "[input]: ";
    cin >> input;

    if (input <= 0) {
        cout << "[err]: invalid input" << endl;
        return 1;
    }

    int digits = 0;
    int copy = input;

    while (copy > 0) {
        digits++;
        copy /= 10;
    }

    int div = 1;
    for (int i = 1; i < digits; i++) {
        div *= 10;
    }

    int bcopy = input;

    for (int i = 0; i < digits; i++) {
        int counter = 0;
        int num = bcopy / div;

        int ccopy = input;
        while (ccopy > 0) {
            int temp = ccopy % 10;

            if (temp == i) {
                counter++;
            }

            ccopy /= 10;
        }

        if (num != counter) {
            cout << "[info] :: [not self descriptive!]" << endl;
            return 0;
        }

        bcopy %= div;
        div /= 10;
    }

    cout << "[info] :: [self descriptive!]" << endl;
}