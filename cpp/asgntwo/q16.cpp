#include <iostream>

using namespace std;

int main(void)
{

	int num;
	cout << "[input]: ";
	cin >> num;
	int propmax = 0;
	int propmax_num = 0;
	for (int temp = 1; temp <= num; temp++)
	{
		int is_prime = 0;
		int is_palindrone = 0;
		int is_armstrong = 0;
		int is_perfect = 0;
		int is_strong = 0;
		int is_automorphic = 0;
		int is_happy = 0;
		int properties = 0;

		// prime and perfect logic
		int divisors = 0;
		int divsum = 0;
		for (int i = 1; i <= temp; i++)
		{
			if (temp % i == 0)
			{
				divisors++;
				if (i != temp)
				{
					divsum += i;
				}
			}
		}
		if (divisors == 2)
		{
			is_prime = 1;
			properties++;
		}
		if (divsum == temp)
		{
			is_perfect = 1;
			properties++;
		}

		// prime and perfect logic end

		// palindrone logic

		int pcopy = temp;
		int palin = 0;
		while (pcopy > 0)
		{
			int digit = pcopy % 10;
			palin = palin * 10 + digit;
			pcopy /= 10;
		}
		if (palin == temp)
		{
			is_palindrone = 1;
			properties++;
		}

		// palindrone logic end

		// armstrong logic
		int digits = 0;
		int copy = temp;
		while (copy > 0)
		{
			digits++;
			copy /= 10;
		}

		int cptwo = temp;
		int armsum = 0;
		while (cptwo > 0)
		{
			int digit = cptwo % 10;
			int powval = 1;
			for (int i = 1; i <= digits; i++)
			{
				powval *= digit;
			}
			armsum += powval;
			cptwo /= 10;
		}

		if (armsum == temp)
		{
			is_armstrong = 1;
			properties++;
		}

		// armstrong logic end

		// strong logic
		int stcpy = temp;
		int stsum = 0;
		while (stcpy > 0)
		{
			int digit = stcpy % 10;
			int fact = 1;
			for (int i = 1; i <= digit; i++)
			{
				fact *= i;
			}
			stsum += fact;
			stcpy /= 10;
		}
		if (stsum == temp && temp != 0)
		{
			is_strong = 1;
			properties++;
		}
		// strong logic end

		// automorhpic logic
		int aucopy = temp;
		int autwocpy = temp;
		int square = temp * temp;

		int nums = 1;
		while (aucopy > 0)
		{
			nums *= 10;
			aucopy /= 10;
		}
		int digit = square % nums;
		if (digit == temp)
		{
			is_automorphic = 1;
			properties++;
		}

		// automorphic logic end

		// happy logic
		if (temp != 0)
		{
			int tmp = temp;
			while (tmp != 1 && tmp != 4)
			{
				int sum = 0;
				while (tmp > 0)
				{
					int digit = tmp % 10;
					sum += digit * digit;
					tmp /= 10;
				}
				tmp = sum;
			}

			if (tmp == 1)
			{
				is_happy = 1;
				properties++;
			}
		}

		// happy logic end
		if (properties > propmax)
		{
			propmax = properties;
			propmax_num = temp;
		}
		if (properties >= 3)
		{
			{
				cout << "[number] :: [properties] " << "[ " << temp << " ]" << " :: " << "[ " << properties << " ]" << endl;
			}
		}
	}
	cout << "[number with max properties] " << propmax_num << endl;
}
