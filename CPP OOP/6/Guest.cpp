#define _CRT_SECURE_NO_WARNINGS
#include "Guest.h"
#include <cstring>
#include <cassert>
#include <iostream>

Guest::Guest(const char* i)
{
	Copy(i);
}

Guest::Guest(const Guest& g)
{
	Copy(g.ip);
}

Guest::~Guest()
{
	Del();
}

Guest& Guest::operator=(const Guest& g)
{
	if (this != &g)
	{
		Del();
		Copy(g.ip);
	}
	return *this;
}

void Guest::print() const
{
	print_own();
}

void Guest::print_own() const
{
	std::cout << "IP: " << ip << std::endl;
}

char* Guest::getIp() const
{
	return ip;
}

void Guest::Copy(const char* i)
{
	ip = new char[strlen(i) + 1];
	assert(ip != NULL);
	strcpy(ip, i);
}

void Guest::Del()
{
	delete[] ip;
}