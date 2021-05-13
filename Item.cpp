#include "Item.h"
bool Item::search(Data _data) {
	TList tmp = head;
	while (tmp != 0 && tmp->data != _data) {
		tmp = tmp->next;
	}
	return tmp != 0;
}

void Item::insert(Data _data){
	addToHead(_data);
}

Item& Item::operator=(const Item& other) {
	TList tmp = other.head;
	while (tmp != nullptr) {
		insert(tmp->data);
		tmp = tmp->next;
	}
	return *this;
}

bool Item::erase(Data _data){
	bool find = false;
	if (head->data == _data) {
		deleteFromHead();
		find = true;
	}
	else {
		TList tmp = find_pNode(_data);
		if (tmp->next != 0) { find = true; }
		deleteAfterNode(tmp);
	}
	return find;
}

Data Item::pop() {
	if (!empty()) {
		Data result = head->data;
		deleteFromHead();
		return result;
	}
}