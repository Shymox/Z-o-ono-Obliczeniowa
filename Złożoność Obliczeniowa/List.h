#pragma once
#include <string>
struct ListElem
{
	int value;
	ListElem*prev, *next;
};
class List
{
private:
	int size;
	ListElem* head, * tail;
	void popElem(ListElem* elem);

public:
	void random(int size);

	void load(std::string name);

	void pushFront(int value);

	void pushBack(int value);

	void push(int value, size_t index);

	void popFront();

	void popBack();

	void pop(int index);

	void popNumber(int number);

	bool search(int number);

	void display();

	void display2();

	void erase();

	List();

	~List();

};

