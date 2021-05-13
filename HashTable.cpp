#include "HashTable.h"

int HashTable::hash_function(Data _data) {
	int hash_result = 0;
	string id = _data.getData();
	int length_name = id.length();
	for (int i = 0; i < length_name; i++) {
		hash_result = (hash_base * hash_result + id[i]) % table_size;
	}
	return hash_result;
}

void HashTable::resize() {
	HashTable copy(*this);
	this->~HashTable();
	table_size = 2 * copy.table_size;
	actual_size = copy.actual_size;
	table = new Item[table_size];
	for (int i = 0; i < copy.table_size; i++) {
		while (!copy.table[i].empty()) {
			this->insert(copy.table[i].pop());
		}
	}
}


HashTable::HashTable(const HashTable& tmp) {
	table_size = tmp.table_size;
	actual_size = tmp.actual_size;
	table = new Item[table_size];
	for (int i = 0; i < table_size; i++) {
		table[i] = tmp.table[i];
	}
}

HashTable::HashTable(const int& _size) {
	table_size = _size;
	actual_size = 0;
	table = new Item[table_size];
}
HashTable::~HashTable() {
	for (int i = 0; i < table_size; i++) {
		table[i].~Item();
    }
	delete[] table;
}

bool HashTable::find(const Data& _data) {
	return table[hash_function(_data)].search(_data);
}
void HashTable::insert(const Data& _data) {
	table[hash_function(_data)].insert(_data);
	actual_size++;
	if (2*actual_size > table_size) {
		resize();
	}
}
void HashTable::erase(const Data& _data) {
	if (table[hash_function(_data)].erase(_data)) {
		actual_size--;
	};
}

ostream& operator<< (ostream& out, const HashTable& hashtable) {
	for (int i = 0; i < hashtable.table_size; i++) {
		out << hashtable.table[i] << endl;
	}
	return out;
}