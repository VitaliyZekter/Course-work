#pragma once
#include<string>
#include<vector>
#include"medicine.h"
#include"order.h"
#include<iostream>
#include<fstream>
using namespace std;
class customer
{
public:
	string name;
	order check;
	customer(string name) { this->name = name; }
	void showCheck()
	{
		float sum = 0;
		for (int i = 0; i < check.drugs.size(); i++)
		{
			cout << endl << check.drugs[i].name << "-------------------" << check.drugs[i].cost << "$";
			sum += check.drugs[i].cost;
		}
		cout << endl << "Total: " << sum << "$";
	}
	void saveCheck(char path[])
	{
		ofstream fin(path, ios_base::app);
		fin << name;
		float sum = 0;
		for (int i = 0;i < check.drugs.size();i++)
		{
			fin << endl << check.drugs[i].name << "-------------------" << check.drugs[i].cost << "$";
			sum += check.drugs[i].cost;
		}
		fin << endl << "Total: " << sum << "$" << endl << "------------------------------------" << endl << endl;
		fin.close();
	}
};

