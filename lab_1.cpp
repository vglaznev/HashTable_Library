#include <iostream>
#include <fstream>
#include <conio.h>
#include "HashTable.h"
using namespace std;

void print_menu() {
	cout << "1. Считать массив данных из файла" << endl;
	cout << "2. Добавить данные" << endl;
	cout << "3. Удалить данные" << endl;
	cout << "4. Проверить на наличие данных" << endl;
	cout << "5. Вывести хеш-таблицу" << endl;
	cout << "ESC. Закончить выполнение программы" << endl;
}


void menu(HashTable& table) {
	char symb = 0;
	while (symb != 27) {
		print_menu();
		symb = _getch();
		system("cls");
		switch (symb) {
		case '1': {
			cout << "Считываем массив данных..." << endl;
			ifstream in("D:\\input.txt");
			Data tmp;
			while(in >> tmp){
				table.insert(tmp);
			}
			cout << "Готово" << endl;
			break;
		}
		case '2': {
			cout << "Введите идентификатор: " << endl;
			Data tmp;
			cin >> tmp;
			table.insert(tmp);
			cout << "Идентификатор добавлен успешно" << endl;
			break;
		}
		case '3': {
			cout << "Введите идентификатор: " << endl;
			Data tmp;
			cin >> tmp;
			table.erase(tmp);
			cout << "Идентификатор удален успешно" << endl;
			break;
		}
		case '4': {
			cout << "Введите идентификатор: " << endl;
			Data tmp;
			cin >> tmp;
			cout << "Идентификатор " << (table.find(tmp) ? "найден" : "не найден") << endl;
			break;
		}
		case '5': {
			cout << table;
			break;
		}
		}
		system("pause");
		system("cls");
	}
}


int main() {
	setlocale(0, "ru");
	HashTable table(29);
	menu(table);
}