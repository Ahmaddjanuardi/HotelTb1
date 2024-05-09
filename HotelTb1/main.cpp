#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

int satu() {
	int quantity;
	int choice;
	//Quantity
	int Qrooms = 0, Qpasta = 0, Qburger = 0, Qnoodles = 0, Qshake = 0, Qchicken = 0;
	//food item Sold
	int Srooms = 0, Spasta = 0, Sburger = 0, Snoodles = 0, Sshake = 0, Schicken = 0;
	//Total price of items
	int Total_room = 0, Total_pasta = 0, Total_burger = 0, Total_noodles = 0, Total_shake = 0, Total_chicken = 0;

	cout << "\n\t Quantity of items we have";
	cout << "\n Rooms avaliable:";
	cin >> Qrooms;
	cout << "\n Quantity of pasta : ";
	cin >> Qpasta;
	cout << "\n Quantity of burger : ";
	cin >> Qburger;
	cout << "\n Quantity of noodles : ";
	cin >> Qnoodles;
	cout << "\n Quantity of shake : ";
	cin >> Qshake;
	cout << "\n Quantity of chicken : ";
	cin >> Qchicken;

	m:
	cout << "\n\t\t\t Plase select from the menu option ";
	cout << "\n\n1) Rooms";
	cout << "\n\n2) Pasta";
	cout << "\n\n3) Burger";
	cout << "\n\n4) Noodles";
	cout << "\n\n5) Shake";
	cout << "\n\n6) Chicken-Tereyaki";
	cout << "\n\n7) Informartion regarding sales and collection ";
	cout << "\n\n8) Exit";

	cout << "\n\n Plase enter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "\n\n Enter the number of rooms you want: ";

		cin >> quantity;
		if (Qrooms - Srooms >= quantity)
		{
			Srooms = Srooms + quantity;
			Total_room = Total_room + quantity*5000;
			cout << "\n\n\t\t" << quantity << "room/rooms have been alloted to you!";
		}
		else
		{
			cout << "\n\tOnly" << Qrooms - Srooms << "Rooms remaining in hotel ";
			break;
		}
	case 2:
		cout << "\n\n Enter Pasta quantity: ";

		cin >> quantity;
		if (Qpasta - Spasta >= quantity)
		{
			Spasta = Spasta + quantity;
			Total_pasta = Total_pasta + quantity * 200;
			cout << "\n\n\t\t" << quantity << "Pasta is the order!";
		}
		else
		{
			cout << "\n\tOnly" << Qpasta - Spasta << "Pasta remaining in hotel ";
			break;
		}
	case 3:
		cout << "\n\n Enter Burger quantity: ";

		cin >> quantity;
		if (Qburger - Sburger >= quantity)
		{
			Sburger = Sburger + quantity;
			Total_burger = Total_burger + quantity * 250;
			cout << "\n\n\t\t" << quantity << "Burger is the order!";
		}
		else
		{
			cout << "\n\tOnly" << Qburger - Sburger << "Burger remaining in hotel ";
			break;
		}
	case 4:
		cout << "\n\n Enter Noodles quantity: ";

		cin >> quantity;
		if (Qnoodles - Snoodles >= quantity)
		{
			Snoodles = Snoodles + quantity;
			Total_noodles = Total_noodles + quantity * 300;
			cout << "\n\n\t\t" << quantity << "Noodles is the order!";
		}
		else
		{
			cout << "\n\tOnly" << Qnoodles - Snoodles << "Pasta remaining in hotel ";
			break;
		}
	case 5:
		cout << "\n\n Enter Shake quantity: ";

		cin >> quantity;
		if (Qshake - Sshake >= quantity)
		{
			Sshake = Sshake + quantity;
			Total_shake = Total_shake + quantity * 50;
			cout << "\n\n\t\t" << quantity << "Shake is the order!";
		}
		else
		{
			cout << "\n\tOnly" << Qshake - Sshake << "Shake remaining in hotel ";
			break;
		}
	case 6:
		cout << "\n\n Enter Chicken Tereyaki quantity: ";

		cin >> quantity;
		if (Qchicken - Schicken >= quantity)
		{
			Schicken = Schicken + quantity;
			Total_chicken = Total_chicken + quantity * 700;
			cout << "\n\n\t\t" << quantity << "Chickeer Tereyaki is the order!";
		}
		else
		{
			cout << "\n\tOnly" << Qchicken - Schicken << "Chicken Tereyaki remaining in hotel ";
			break;
		}
	case 7:
		cout << "\n\t\tDetails of sales and collection ";
		cout << "\n\n Number of rooms we had : " << Qrooms;
		cout << "\n\n Number of rooms we gave for rent " << Srooms;
		cout << "\n\n remaining rooms : " << Qrooms - Srooms;
		cout << "\n\n Total rooms collection for the day : " << Total_room;

		cout << "\n\n Number of Pasta we had : " << Qpasta;
		cout << "\n\n Number of pasta we sold " << Spasta;
		cout << "\n\n remaining Pasta : " << Qpasta - Spasta;
		cout << "\n\n Total Pasta collection for the day : " << Total_pasta;

		cout << "\n\n Number of Burger we had : " << Qburger;
		cout << "\n\n Number of Burger we sold " << Sburger;
		cout << "\n\n remaining Burger : " << Qburger - Sburger;
		cout << "\n\n Total Burger collection for the day : " << Total_burger;

		cout << "\n\n Number of Noodles we had : " << Qnoodles;
		cout << "\n\n Number of Noodles we sold " << Snoodles;
		cout << "\n\n remaining Noodles : " << Qnoodles - Snoodles;
		cout << "\n\n Total Noodles collection for the day : " << Total_noodles;

		cout << "\n\n Number of Shake we had : " << Qshake;
		cout << "\n\n Number of Shake we sold " << Sshake;
		cout << "\n\n remaining Shake : " << Qshake - Sshake;
		cout << "\n\n Total Shake collection for the day : " << Total_shake;

		cout << "\n\n Number of Chicken Tereyaki we had : " << Qchicken;
		cout << "\n\n Number of Chicken Tereyaki we sold " << Schicken;
		cout << "\n\n remaining Chicken Tereyaki : " << Qchicken - Schicken;
		cout << "\n\n Total Chicken Tereyaki collection for the day : " << Total_chicken;

		cout << "n\n\n Total Collection for the day: "<<Total_room+Total_pasta+Total_burger+Total_noodles+Total_shake+Total_chicken;
	case8:
		exit(0);

	default:
		cout << "\n Plase select the number mentioned above!";
	}
	goto m;
}