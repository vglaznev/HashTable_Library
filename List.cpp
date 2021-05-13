#include "List.h"

List::List() : head(nullptr) {}
List::~List() {
	while (!empty()) {
		deleteFromHead();
	}
}

//List& List::operator= (const List& other) {
//	TList tmp = other.head;
//	if (tmp != nullptr) {
//		this->addToHead(tmp->data);
//		tmp = tmp->next;
//		TList tmp_th = head;
//		while (tmp != nullptr) {
//			this->addAfterNode(tmp_th,tmp->data);
//			tmp = tmp->next;
//			tmp_th = tmp_th->next;
//		}
//	}
//	return *this;
//}

void List::addAfterNode(TList pNode, Data _data) {
	TList tmp = new Node(_data);
	tmp->next = pNode->next;
	pNode->next = tmp;
}
void List::deleteAfterNode(TList pNode) {
	if (pNode->next != 0) {
		TList tmp = pNode->next;
		pNode->next = tmp->next;
		delete tmp;
	}
}

List::TList List::find_pNode(Data _data) {
	TList tmp = head;
	while (tmp->next != 0 && !(tmp->next->data == _data))
		tmp = tmp->next;
	return tmp;
}

bool List::empty() {
	return head == 0;
}

void List::deleteFromHead() {
	if (!empty()) {
		TList tmp = head;
		head = head->next;
		delete tmp;
	}
}
void List::addToHead(Data _data) {
	TList tmp = new Node(_data);
	tmp->next = head;
	head = tmp;
}

ostream& operator<< (ostream& out, const List& list) {
	List::TList tmp = list.head;
	while (tmp != 0) {
		out << tmp->data << ' ';
		tmp = tmp->next;
	}
	return out;
}