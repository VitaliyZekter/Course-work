#pragma once
#include<string>
#include<vector>
#include"medicine.h"
#include"order.h"
#include<iostream>
#include<fstream>
#include"customer.h"

using namespace std;
class Apothecary
{
public:
	vector<customer>clients;
	vector<medicine>stock;
	void showDamOrg()
	{
		for (int i = 0; i < stock.size(); i++)
		{
			cout << endl << stock[i].id << ") " << stock[i].DamagedOrgan << "--" << stock[i].name;
		}
	}
	void addNewMedicine(medicine md)
	{
		this->stock.push_back(md);
	}
	void addMedicines(int id, int count)
	{
		bool findItem = false;
		for (int i = 0;i < stock.size();i++)
		{
			if (stock[i].id == id)
			{
				stock[i].count += count;
				findItem = true;
				break;
			}
		}
		if (findItem == false)
		{
			cout << endl << "Medicine was not found!";
		}
	}
	void showList()
	{
		for (int i = 0; i < stock.size(); i++)
		{
			cout << endl << stock[i].id << ") " << stock[i].name << "-----" << stock[i].cost << "$";
		}
		cout << endl;
	}
	void AddCostumer(customer newCustomer)
	{
		this->clients.push_back(newCustomer);
	}

	bool BuyMedicine(int id, string ClientName)
	{
		int index;
		for (int i = 0;i < clients.size(); i++)
		{
			if (clients[i].name == ClientName)
			{
				index = i;
				clients[i].check.name = ClientName;
				break;
			}
		}
		medicine m = searchMed(id);
		if (m.id != -1)
		{
			clients[index].check.drugs.push_back(m);
			removeMedicine(id);
			return true;
		}
		else return false;
	}
	void removeMedicine(int id)
	{
		for (int i = 0; i < stock.size();i++)
		{
			if (stock[i].id == id)
			{
				if (stock[i].count > 1)
				{
					stock[i].count--;
				}
				else stock.erase(stock.begin() + i);
				break;
			}
		}
	}

	medicine searchMed(int id)
	{
		for (int i = 0;i < stock.size();i++)
		{
			if (stock[i].id == id) return stock[i];
		}
		medicine m;
		m.id = -1;
		return m;
	}
	char* readData(string filepath)
	{
		char data[20000] = "";
		ifstream fin(filepath);
		for (int i = 0;!fin.eof();i++)
		{
			fin >> data[i];
			data[i + 1] = '\n';
		}
		fin.close();
		string temp = "";
		int count = 0;
		medicine m = medicine();
		for (int i = 0;i < strlen(data);i++)
		{
			if (data[i] == '#')
			{
				m.DamagedOrgan = temp;
				temp = "";count = 0;
				this->stock.push_back(m);
			}
			else if (data[i] == ',')
			{
				switch (count)
				{
				case 0:
				{
					m.id = stoi(temp);
					break;
				}
				case 1:
				{
					m.cost = stof(temp);
					break;
				}
				case 2:
				{
					m.name = temp;
					break;
				}
				case 3:
				{
					m.count = stoi(temp);
					break;
				}
				}
				temp = "";count++;
			}
			else
			{
				temp += data[i];
			}
		}
		return data;
	}
	void rewrite()
	{
		ofstream fin("stock.txt");
		for (int i = 0; i < stock.size(); i++)
		{
			fin << stock[i].id << ',' << stock[i].cost << ',' << stock[i].name << ',' << stock[i].count << ',' << stock[i].DamagedOrgan << '#' << endl;
		}
		fin.close();
	}
};

