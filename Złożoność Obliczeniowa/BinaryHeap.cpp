#include "BinaryHeap.h"
#include <iostream>
#include <fstream>

/*
Klasa zawieraj¹ca Kopiec oraz funkcje potrzebne do jego obs³ugi
*/
//funkcja zwraca index rodzica wezla o podanym indexie
size_t BinaryHeap::parentIndex(int index)
{	
	return (index-1)/2;
}
//funkcja zwraca index lewego dziecka wezla o podanym indexie
size_t BinaryHeap::childLeftIndex(int index)
{
	return 2*index+1;
}
//funkcja zwraca index prawego dziecka wezla o podanym indexie
size_t BinaryHeap::childRightIndex(int index)
{
	return 2*index+2;
}
//funkcja pobiera kopiec z pliku
void BinaryHeap::load(std::string name)
{
	this->size = 0;
	std::fstream file;
	file.open(name, std::ios::in | std::ios::out);
	if (file.good() == true)
	{
		size_t size = 0;
		std::cout << "Uzyskano dostep do pliku!" << std::endl;
		std::string data;
		getline(file, data);
		try {
			size = static_cast<size_t>(std::stoi(data));
		}
		catch (std::exception)
		{
			std::cout << "B³¹d odczytu: std::exception" << '\n';
		}
		this->size = 0;
		while (!file.eof() && this->size < size)
		{
			getline(file, data);
			try
			{
				push(static_cast<int>(std::stoi(data)));
			}
			catch (std::exception)
			{
				std::cout << "Blad odczytu: std::exception" << '\n';
			}
		}
		file.close();
		if ((this->size) < size)
		{
			std::cout << "Blad odczytu: Rozmiar listy wiekszy niz ilosc danych" << '\n';
			this->size = 0;
		}
	}
	else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;
}
//funkcja tworzy kopiec o podanej wielkosci z losowymi wartosciami
void BinaryHeap::random(int size)
{
	this->size = 0;
	for (int i = 0;i < size;i++)
	{
		push(rand());
	}
}
//funkcja naprawia kopiec w dó³
void BinaryHeap::fixDown(int index)
{
	while (this->tab[this->childLeftIndex(index)] > this->tab[index] || this->tab[this->childRightIndex(index)] > this->tab[index])
	{
		std::cout << "a";
		if (this->tab[this->childLeftIndex(index)] > this->tab[this->childRightIndex(index)])
		{
			int temp = tab[this->childLeftIndex(index)];
			this->tab[this->childLeftIndex(index)] = tab[index];
			this->tab[index] = temp;
			index = this->childLeftIndex(index);
		}
		else
		{
			int temp = tab[this->childRightIndex(index)];
			this->tab[this->childRightIndex(index)] = this->tab[index];
			this->tab[index] = temp;
			index = this->childRightIndex(index);
		}
	}
}
//funkcja naprawia kopiec w górê
void BinaryHeap::fixUp(int index)
{
	while (this->tab[parentIndex(index)] < this->tab[index])
	{
		int temp = tab[this->parentIndex(index)];
		this->tab[this->parentIndex(index)] = this->tab[index];
		this->tab[index] = temp;
		index = this->parentIndex(index);
	}
}
//dodawanie wartoœci do kopca
void BinaryHeap::push(int value)
{
	int i = this->size;
	this->tab[this->size] = value;
	this->size++;
	while (i != 0 && this->tab[parentIndex(i)] < this->tab[i])
	{
		int temp = this->tab[this->parentIndex(i)];
		this->tab[this->parentIndex(i)] = this->tab[i];
		this->tab[i] = temp;
		i = this->parentIndex(i);
	}
	fixUp(i);
}
//usuwanie podanego numeru z kopca
void BinaryHeap::pop(int number)
{
	size_t index=0;
	for (index = 0;index < this->size;index++)
	{
		if (this->tab[index] == number)
		{
			break;
		}
		return;
	}
	this->tab[index] = this->tab[this->size - 1];
	this->size--;
	fixUp(index);
	fixDown(index);
}
//dodanie wartosci do tablicy kopca
void BinaryHeap::add(int value)
{
	this->tab[size] = value;
	size++;
}
//wyszukiwanie wartosci w kopcu (zwraca true jesli znajdzie)
bool BinaryHeap::search(int number)
{
	for (int i = 0;i < this->size;i++)
	{
		if (this->tab[i] == number)
		{
			return true;
		}
	}
	return false;
}
//wyswietlanie kopca
void BinaryHeap::display(std::string sp, std::string sn, size_t v)
{
		std::string s;

		if (v < this->size)
		{
			s = sp;
			if (sn == cr) s[s.length() - 2] = ' ';
			display(s + cp, cr, 2 * v + 2);

			s = s.substr(0, sp.length() - 2);

			std::cout << s << sn << this->tab[v] << std::endl;

			s = sp;
			if (sn == cl) s[s.length() - 2] = ' ';
			display(s + cp, cl, 2 * v + 1);
		}
}

//wyswietlanie tablicy kopca
void BinaryHeap::displayTable()
{
	for (int i = 0;i < size;i++)
	{
		std::cout << tab[i] << " ";
	}
}



BinaryHeap::BinaryHeap()
{
	this->tab = new int[SIZEMAX];
	this->size = 0;
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
}

BinaryHeap::~BinaryHeap()
{
	delete[] this->tab;
}
