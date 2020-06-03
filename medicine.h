#pragma once
#include<string>
using namespace std;
class medicine
{
public:
	string DamagedOrgan;
	string name;
	float cost;
	int id;
	int count;
	medicine() {}
	medicine(int id, float cost, string name, int count) { this->cost = cost; this->count = count; this->id = id; this->name = name; }
};

