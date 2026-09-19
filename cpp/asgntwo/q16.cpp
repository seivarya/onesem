#include <iostream>

using namespace std;

int main(void)
{
	int is_prime = 0;
	int is_palindrone = 0;
	int is_armstrong = 0;
	int is_perfect = 0;
	int is_strong = 0;
	int is_automorphic = 0;
	int is_happy = 0;

	int num = 3;
	int propmax = 0;
	int properties = 0;
	for (int temp = 0; temp <= num; temp++)
	{
		// prime logic
		int divisors = 0;
		for (int i = 1; i <= temp; i++)
		{
			if (temp % i == 0)
			{
				divisors++;
			}
		}
		if (divisors == 2)
		{
			is_prime = 1;
			properties++;
		}
		// prime logic end

		// palindrone logic

		// palindrone logic end

		// armstrong logic

		// armstrong logic end

		// perfect logic

		// perfect logic end

		// strong logic

		// strong logic end

		// automorhpic logic

		// automorphic logic end

		// happy logic

		// happy logic end

		if (properties >= 1)
		{
			cout << "[number] :: [properties] " << "[ " << temp << " ]" << " :: " << "[ " << properties << " ]" << endl;
			cout << "[number] :: " << temp << endl;
		}
	}

	cout << "[number with max properties] " << propmax << endl;
}
// Question 16. For every number from 1 to N, determine whether it satisfies each of
// the following properties:
// 1. Prime
// 2. Palindrome
// 3. Armstrong
// 4. Perfect
// 5. Strong
// 6. Automorphic
// 7. Happy