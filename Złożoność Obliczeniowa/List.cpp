#include "List.h"
#include <iostream>
#include <conio.h>
#include <time.h>
#include <fstream>

/*
Klasa zawieraj�ca List� oraz funkcje potrzebne do jej obs�ugi
*/
//Usuwanie elementu z listy
void List::popElem(ListElem* elem)
{
	if (elem==head)
	{
		popFront();
		//std::cout << "b";
		return;
	}
	if (elem==tail)
	{
		//std::cout << "c";
		popBack();
		return;
	}
		elem->next->prev = elem->prev;
		elem->prev->next = elem->next;
		delete elem;
		this->size--;
}
//Utworzenie listy z losowych element�w o podanym rozmiarze
void List::random(int size)
{
	this->erase();
	for (int i = 0; i < size;i++)
	{
		pushBack(rand());
	}
}
//Za�adowanie listy z pliku
void List::load(std::string name)
{
	this->erase();
	std::fstream file;
	file.open(name, std::ios::in | std::ios::out);
	if (file.good() == true)
	{
		size_t size=0;
		std::cout << "Uzyskano dostep do pliku!" << std::endl;
		std::string data;
		getline(file, data);
		try {
			size = static_cast<size_t>(std::stoi(data));
		}
		catch (std::exception)
		{
			std::cout << "B��d odczytu: std::exception" << '\n';
		}
		this->size = 0;
		while (!file.eof() && this->size < size)
		{
			getline(file, data);
			try
			{
				pushBack(static_cast<int>(std::stoi(data)));
			}
			catch (std::exception)
			{
				std::cout << "Blad odczytu: std::exception" << '\n';
			}
		}
		file.close();
		if ((this->size) < size)
		{
			this->erase();
			std::cout << "Blad odczytu: Rozmiar listy wiekszy niz ilosc danych" << '\n';
			this->size = 0;
		}
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
	system("pause");
}
//Dodanie elementu na pocz�tek listy
void List::pushFront(int value)
{
	ListElem* temp = new ListElem();
	temp->value = value;
	temp->prev = nullptr;
	temp->next = this->head;
	if (head != nullptr)
	{
		this->head->prev = temp;
	}
	else
	{
		this->tail = temp;
	}
	this->head = temp;
	this->size++;
}
//Dodanie elementu na koniec listy
void List::pushBack(int value)
{
	ListElem* temp = new ListElem();
	temp->value = value;
	temp->next = nullptr;
	temp->prev = this->tail;
	if (tail != nullptr)
	{
		this->tail->next = temp;
	}
	else
	{
		this->head = temp;
	}
	this->tail = temp;
	this->size++;
}
//Dodanie elementu na miejsce w liscie o podanym numerze
void List::push(int value, size_t index)
{	

	if (index == 0)
		{
			pushFront(value);
		} 
	else if (index == size)
		{
			pushBack(value);
		}
	else if (0 < index < size)
	{
		ListElem* temp = this->head;
		while (index)
		{
			temp = temp->next;
			index--;
		}
		ListElem* tmp = new ListElem();
		tmp->value = value;
		tmp->next = temp;
		tmp->prev = temp->prev;
		temp->prev->next = tmp;
		temp->prev = tmp;
		
		this->size++;
	}
}
//Usuniecie elementu z pocz�tku listy
void List::popFront()
{
	if (this->head != nullptr)
	{	
		if (size == 1)
		{
			this->tail = nullptr;
			this->head = nullptr;
		}
		else if (size == 2)
		{
			ListElem* temp = this->head;
			delete temp;
			this->tail->prev = nullptr;
			this->head = tail;
		}
		else if (size != 0)
		{
			ListElem* temp = this->head;
			this->head = this->head->next;
			this->head->prev = nullptr;
			delete temp;
		}
		this->size--;
	}

}
//Usuniecie elementu z konca listy
void List::popBack()
{
	if (this->tail != nullptr)
	{
		this->size--;
		if (size == 0)
		{	
			this->tail = nullptr;
			this->head = nullptr;
			return;
		}
		if (size == 1)
		{
			ListElem* temp = this->tail;
			delete temp;
			this->head->next = nullptr;
			this->tail = head;
		}
		else if(size!=0)
		{
			ListElem* temp = this->tail;
			this->tail = this->tail->prev;
			this->tail->next = nullptr;
			delete temp;
		}
	}
}
//Usuniecie elementu o podanym indeksie
void List::pop(int index)
{
		if (index == 0)
		{
			popFront();
		}
		else if (index == size)
		{
			popBack();
		}
		else if (0 < index && index < size)
		{
			ListElem* temp = this->head;
			while (index)
			{
				temp = temp->next;
				index--;
			}
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
			this->size--;
		}
}
//usuniecie podanego numeru z listy
void List::popNumber(int number)
{
	if (this->head != nullptr)
	{
		ListElem* temp = this->head;
		while (temp != nullptr)
		{

			if (temp->value == number)
			{
				ListElem* tmp =temp->next;
				popElem(temp);
				temp = tmp;
			}
			else
			{
				temp = temp->next;
			}
		}
	}

}
//wyszukiwanie wartos�i, je�li znaleziono zwraca true
bool List::search(int number)
{
	if (this->head)
	{
		ListElem* temp = this->head;
		while (temp != nullptr)
		{
			if (temp->value == number) return true;
			temp = temp->next;
		}
	}
	return false;
}
//Wy�wietlanie listy
void List::display()
{
	ListElem* temp = this->head;
	while (temp != nullptr)
	{
		std::cout << temp->value <<" ";
		temp =temp->next;

	}

}
//Wy�wietlanie listy w odwrotnej kolejno�ci
void List::display2()
{
	ListElem* temp = this->tail;
	while (temp != nullptr)
	{
		std::cout << temp->value << " ";
		temp = temp->prev;

	}

}
//Kasowanie listy
void List::erase()
{	
	while (this->head != nullptr)
	{

		ListElem* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
	this->size = 0;
	this->tail = nullptr;
}

List::List()
{
	this->size = 0;
	this->head=nullptr;
	this->tail=nullptr;
}

List::~List()
{
	this->erase();
}
