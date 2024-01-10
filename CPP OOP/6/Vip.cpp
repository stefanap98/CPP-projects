#define _CRT_SECURE_NO_WARNINGS
#include "Vip.h"
#include <iostream>
#include <cassert>
#include <cstring>

Vip::Vip(const char* IP, const char* UN, const char* PW, const char* T) : User(IP,UN,PW,T)
{}

Vip::Vip(const Vip& V) : User(V)
{}

Vip& Vip::operator=(const Vip& V)
{
	if (this != &V)
	{
		User::operator=(V);
	}
	return *this;
}

void Vip::print() const
{
	User::print();
	print_own();
}

void Vip::print_own() const
{
	std::cout << "You are a vip!" << std::endl;
}

void Vip::changeTitle(const char* T)
{
	std::cout << "Changed Title!" << std::endl;
	if (title != NULL)
	{
		delete[] title;
	}
	title = new char[strlen(T) + 1];
	assert(title != NULL);
	strcpy(title, T);
}