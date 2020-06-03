#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<conio.h>
#include"medicine.h"
#include"order.h"
#include"customer.h"
#include"Apothecary.h"
using namespace std;
int main()
{

	Apothecary d1;
	d1.readData("stock.txt");
	int ans;
	cout << "1 - Enter as a customer; 2 - Enter as administrator\n";
	cin >> ans;
	if (ans == 1) {
		cout << "     Welcom to our drugstore\n";
		cout << "Enter your name: ";
		string name;
		cin >> name;
		d1.AddCostumer(customer(name));
		cout << "Hello, " << name;
		while (true) {

			cout << endl << "Chose the medicine - 1 " << endl << "Ask the pharmacist for advice - 2" << endl << "Complete the purchase - 0\n";
			cin >> ans;
			if (ans == 1)
			{
				int idi;
				d1.showList();
				cin >> idi;
				d1.BuyMedicine(idi, d1.clients[0].name);
			}
			else  if (ans == 2)
			{
				int idi;
				d1.showDamOrg();
				cin >> idi;
				d1.BuyMedicine(idi, d1.clients[0].name);
			}
			else if (ans == 0)
			{
				d1.clients[0].showCheck();
				d1.rewrite();
				_getch();
				break;
			}
			system("cls");
		}
		cout << endl << "Goodbay, " << name << '!' << endl;
		
	}
	else if (ans == 2)
	{

		while (1) {
			cout << "1 - add a new medicine; 2 - add medicines; 3 - exit";
			cin >> ans;
			if (ans == 1)
			{

				medicine m;
				m.id = d1.stock.size() + 1;
				cout << endl << "Enter name for new medicine: ";
				cin >> m.name;
				cout << endl << "Enter count for new medicine: ";
				cin >> m.count;
				cout << endl << "Enter damage ordan for new medicine: ";
				cin >> m.DamagedOrgan;
				cout << endl << "Enter cost for new medicine: ";
				cin >> m.cost;
				d1.addNewMedicine(m);
			}
			else if (ans == 2)
			{
				d1.showList();
				int idi;
				int count;
				cout << endl << "Enter id: ";
				cin >> idi;
				cout << endl << "Enter count: ";
				cin >> count;
				d1.addMedicines(idi, count);
			}
			else if (ans == 3)
			{
				d1.rewrite();
				break;
			}
		}
	}
	system("pause");
}
