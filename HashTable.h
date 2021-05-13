#include "Item.h"
class HashTable {
	Item* table;
	int hash_function(Data);
	static const int hash_base = 31;
	int table_size, actual_size;
	void resize();
public:
	HashTable(const int&);
	~HashTable();

	HashTable(const HashTable&);

	bool find(const Data&);
	void insert(const Data&);
	void erase(const Data&);
	friend ostream& operator<< (ostream&, const HashTable&);
};