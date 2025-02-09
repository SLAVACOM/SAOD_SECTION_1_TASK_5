#include <iostream>
#include <regex>
#include <windows.h>

using namespace std;   

const int QUEUE_SIZE = 1;

struct Queue {
	int first, last;
	int data[QUEUE_SIZE];
	int count = 0;

	void init() {
		first = 0;
		last = 0;
	}

	bool isEmpty() {
		return count == 0;
	}

	bool isFull() {
		return count >= QUEUE_SIZE;
	}

	void push(int value) {
		if (isFull()) {
			cout << "ОЧЕРЕДЬ ПЕРЕПОЛНЕНА - ДОБАВЛЕНИЕ НЕВОЗМОЖНО" << endl;
			return;
		}
		data[last] = value;
		last = (last + 1) % QUEUE_SIZE;
		count++;
	}

	int pop() {
		if (isEmpty()) {
			cout << "ОЧЕРЕДЬ ПУСТАЯ - НЕЧЕГО НЕЛЬЗЯ УДАЛИТЬ" << endl;
			return -1;
		}
		int value = data[first];
		first = (first + 1) % QUEUE_SIZE;
		count--;
		return value;
	}

	void print() {
		if (isEmpty()) {
			cout << "ОЧЕРЕДЬ ПУСТАЯ" << endl;
			return;
		}
		cout << "ОЧЕРЕДЬ: ";
		int i = first;
		do {
			cout << data[i] << " ";
			i = (i + 1) % QUEUE_SIZE;
		} while (i != last);
		cout << endl;
	}
} ring;


int validIntegerInput(string message) {
	string input;
	regex valid("[1-9][0-9]*");
	do {
		cout << message;
		cin >> input;
	} while (!regex_match(input, valid));
	return stoi(input);
}

void menu(bool& exit) {
	cout << "\nМЕНЮ" << endl;
	cout << "1. Проверить очередь на пустоту" << endl;
	cout << "2. Проверить очередь на заполненность" << endl;
	cout << "3. Добавить элемент в конец очереди" << endl;
	cout << "4. Удалить элемент из начала очереди" << endl;
	cout << "5. Вывести очередь на экран" << endl;
	cout << "6. Выход" << endl;
	int choice = validIntegerInput("Ваш выбор: ");
	switch (choice) {
	case 1:
		cout << "ОЧЕРЕДЬ " << (ring.isEmpty() ? "ПУСТАЯ" : "НЕ ПУСТАЯ") << endl;
		break;
	case 2:
		cout << "ОЧЕРЕДЬ " << (ring.isFull() ? "ЗАПОЛНЕНА" : "НЕ ЗАПОЛНЕНА") << endl;
		break;
	case 3:
		ring.push(validIntegerInput("Введите значение: "));
		break;
	case 4:
		cout << "Удален элемент: " << ring.pop() << endl;
		break;
	case 5:
		ring.print();
		break;
	case 6:
		exit = true;
		break;
	}
}

int main(){
	setlocale(LC_ALL, "RUS");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	ring.init();
	bool exit = false;
	while (!exit){
		menu(exit);
	}

}
