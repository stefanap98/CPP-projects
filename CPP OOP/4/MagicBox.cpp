#include "MagicBox.h"
#include <iostream>
#include <random>

template <class T>
MagicBox<T>::MagicBox(int max)
{
	size = max;
	Box = new T[size];
	top = -1;
}

template <class T>
MagicBox<T>::MagicBox(const MagicBox<T>& m)
{
	size = m.size;
	top = m.top;
	Box = new T[size];
	for (int i = 0; i <= top; i++)
	{
		Box[i] = m.Box[i];
	}
}

template <class T>
MagicBox<T>::~MagicBox()
{
	delete[] Box;
}

template <class T>
MagicBox<T>& MagicBox<T>::operator=(const MagicBox<T>& m)
{
	if (this != &m)
	{
		delete[] Box;
		size = m.size;
		top = m.top;
		for (int i = 0; i <= top; i++)
		{
			Box[i] = m.Box[i];
		}
	}
	return *this;
}

template <class T>
bool MagicBox<T>::empty() const
{
	return top == -1;
}

template <class T>
bool MagicBox<T>::full() const
{
	return top == size - 1;
}

template <class T>
void MagicBox<T>::insert(T c)
{
	if (full())
	{
		std::cout << "MagicBox is full!" << std::endl;
		return ;
	}
	Box[++top] = c;
}

template <class T>
T MagicBox<T>::pop()
{
	if (empty())
	{
		std::cout << "MagicBox is empty!" << std::endl;
		return 0;
	}

	int elem = Random(top);

	T random = Box[elem];

	if (top > 0)
	{
		for (int i = elem; i < top; i++)
		{
			Box[i] = Box[i + 1];
		}

		top--;
	}
	else
	{
		top = -1;
	}

	return random;
}

template <class T>
void MagicBox<T>::list() const
{
	std::cout << "MagicBox:" << " ";
	for (int i = top; i >= 0; i--)
	{
		std::cout << Box[i] << " ";
	}
}

template <class T>
int MagicBox<T>::Random(int max) const
{
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, max); // define the range

	return distr(eng);
}