#include "List.h"
class Item : public List {
public:
	bool search(Data);
	void insert(Data);
	bool erase(Data);

	Item& operator=(const Item&);

	Data pop();
};