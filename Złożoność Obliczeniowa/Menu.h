#pragma once
#include <string>
#include <string>
#include "Array.h"
#include "List.h"
#include "BinaryHeap.h"
#include "BST.h"
#include "Timer.h"
class Menu
{
private:
	double time = 0;
	int page=0;
	int index=0;
	bool exit = true;
	const int SIZEX = 3;
	const int SIZEY = 5;
	std::string nazwa(int page);
	Array* array;
	List* list;
	BinaryHeap* heap;
	BST* tree;
	Timer* timer;

public:
	void loop();

	void display();

	void input();

	void writeTime(double time);

	Menu();

	~Menu();
};

