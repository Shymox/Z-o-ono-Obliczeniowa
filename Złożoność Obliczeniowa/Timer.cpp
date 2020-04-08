#include "Timer.h"
#include <Windows.h>
#include <iostream>

/*
Klasa zawieraj�ca pomiar czasu
*/

double frequency = 0.0;
__int64 counterstart = 0;
//Zeruje i startuje pomiar czasu
void Timer::startCounter()
{
LARGE_INTEGER largeInt;
if (!QueryPerformanceFrequency(&largeInt))
std::cout << "Blad pomiaru czasu!"<<'\n';

frequency = double(largeInt.QuadPart) / 1000.0;

QueryPerformanceCounter(&largeInt);
counterstart = largeInt.QuadPart;
}
//Wy�wietla warto�� pomiaru
double Timer::getCounter()
{
    LARGE_INTEGER largeInt;
    QueryPerformanceCounter(&largeInt);
    return double(largeInt.QuadPart - counterstart) / frequency;
}

Timer::Timer()
{

}

Timer::~Timer()
{

}
