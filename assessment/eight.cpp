#include <iostream>
using namespace std;

int SEATS[30] = {0};

void reserve(int *total, int *count);
void cancel();
void avail();
void reserv();
void bill(int *total, int *count);

int main(void)
{
	int choice;
	int total = 0;
	int count = 0;

	while (1)
	{
		cout << "\n[1]: RESERVE" << endl;
		cout << "[2]: CANCEL" << endl;
		cout << "[3]: DISPLAY AVAILABLE" << endl;
		cout << "[4]: DISPLAY RESERVED" << endl;
		cout << "[5]: CALCULATE BILL" << endl;
		cout << "[0]: EXIT" << endl;

		cout << "[input] :: enter choice  ";
		cin >> choice;

		if (choice == 1)
			reserve(&total, &count);
		else if (choice == 2)
			cancel();
		else if (choice == 3)
			avail();
		else if (choice == 4)
			reserv();
		else if (choice == 5)
			bill(&total, &count);
		else if (choice == 0)
			break;
		else
			cout << "[err]: incorrect choice" << endl;
	}

	return 0;
}

void reserve(int *total, int *count)
{
	int seat_no;
	int seat_type;
	int price;

	cout << "[input] :: enter seat number  ";
	cin >> seat_no;

	if (seat_no < 1 || seat_no > 30)
	{
		cout << "[err]: incorrect seat number" << endl;
		return;
	}

	if (SEATS[seat_no - 1] != 0)
	{
		cout << "[err]: seat already reserved" << endl;
		return;
	}

	cout << "[1]: STANDARD - Rs 180" << endl;
	cout << "[2]: PREMIUM  - Rs 250" << endl;
	cout << "[3]: RECLINER - Rs 400" << endl;

	cout << "[input] :: enter seat type  ";
	cin >> seat_type;

	if (seat_type == 1)
		price = 180;
	else if (seat_type == 2)
		price = 250;
	else if (seat_type == 3)
		price = 400;
	else
	{
		cout << "[err]: incorrect seat type" << endl;
		return;
	}

	SEATS[seat_no - 1] = seat_type;

	*total += price;
	*count += 1;

	cout << "[success]: seat reserved" << endl;
}

void cancel()
{
	int seat_no;

	cout << "[input] :: enter seat number  ";
	cin >> seat_no;

	if (seat_no < 1 || seat_no > 30)
	{
		cout << "[err]: incorrect seat number" << endl;
		return;
	}

	if (SEATS[seat_no - 1] == 0)
	{
		cout << "[err]: seat is already available" << endl;
		return;
	}

	SEATS[seat_no - 1] = 0;

	cout << "[success]: seat cancelled" << endl;
}

void avail()
{
	cout << "\n[available seats]" << endl;

	for (int i = 0; i < 30; i++)
	{
		if (SEATS[i] == 0)
			cout << i + 1 << " ";
	}

	cout << endl;
}

void reserv()
{
	cout << "\n[reserved seats]" << endl;

	for (int i = 0; i < 30; i++)
	{
		if (SEATS[i] != 0)
		{
			cout << i + 1;

			if (SEATS[i] == 1)
				cout << " - STANDARD";
			else if (SEATS[i] == 2)
				cout << " - PREMIUM";
			else
				cout << " - RECLINER";

			cout << endl;
		}
	}
}

void bill(int *total, int *count)
{
	double discount = 0;
	double final_bill;

	if (*count == 0)
	{
		cout << "[err]: no seats booked" << endl;
		return;
	}

	if (*count >= 5)
		discount = *total * 0.10;

	final_bill = *total - discount;

	cout << "\n[subtotal]    : Rs " << *total << endl;
	cout << "[discount]    : Rs " << discount << endl;
	cout << "[final bill]  : Rs " << final_bill << endl;
}
