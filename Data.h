#pragma once
#include <iostream>
using namespace std;

class Data {
	string id;
public:
	Data();
	Data(string);

	bool operator==(Data);
	bool operator!=(Data);
	string getData();

	friend istream& operator>>(istream&, Data&);
	friend ostream& operator<<(ostream&, const Data&);
};