#pragma once
#include "Data.h"
class List {
protected:
	struct Node {
		Data data;
		Node* next;
		Node(Data _data) : data(_data), next(0) {}
	};
	typedef Node* TList;
	TList head;

	void addAfterNode(TList, Data);
	void deleteAfterNode(TList);
	TList find_pNode(Data);
public:

	List();
	~List();

	/*List& operator= (const List&);*/

	bool empty();
	
	void deleteFromHead();
	void addToHead(Data);

	friend ostream& operator<< (ostream&, const List&);
};