#pragma once
#include <string>

class BinaryHeap
{
private:
	const size_t SIZEMAX = 65000;

	size_t size;

	int* tab;

	size_t parentIndex(int index);

	size_t childLeftIndex(int index);

	size_t childRightIndex(int index);
	
	std::string cr, cl, cp;
public:
	void load(std::string name);

	void random(int size);

	void fixDown(int index);

	void fixUp(int index);

	void push(int value);

	void pop(int number);

	void add(int value);

	bool search(int number);

	void display(std::string sp, std::string sn, size_t i);

	void displayTable();

	BinaryHeap();

	~BinaryHeap();
};


