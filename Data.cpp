#include "Data.h"
Data::Data(){}
Data::Data(string _id) : id(_id) {}

bool Data::operator==(Data data) {
	return id == data.id;
}

bool Data::operator!=(Data data) {
	return !(*this == data);
}

string Data::getData(){
	return id;
}

istream& operator>>(istream& in, Data& data) {
	in >> data.id;
	return in;
}
ostream& operator<<(ostream& out, const Data& data) {
	out << data.id;
	return out;
}