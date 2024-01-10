#define _CRT_SECURE_NO_WARNINGS
#include "Admin.h"
#include <iostream>
#include <cassert>
#include <cstring>

Admin::Admin(const char* IP, const char* UN, const char* PW, const char* T, int REP) : User(IP,UN,PW,T) , PowerUser(IP,UN,PW,T,REP) , Vip(IP,UN,PW,T)
{}

Admin::Admin(const Admin& a) : User(a) , PowerUser(a) , Vip(a)
{}

Admin& Admin::operator=(const Admin& a)
{
	if (this != &a)
	{
		PowerUser::operator=(a);
		Vip::operator=(a);
	}
	return *this;
}

void Admin::print() const
{
	Guest::print_own();
	User::print_own();
	PowerUser::print_own();
	Vip::print_own();
	print_own();
}

void Admin::print_own() const
{
	std::cout << "You are an admin!" << std::endl;
}

void Admin::ChangeOwnUsername(const char* N)
{
	if (username != NULL)
	{
		delete[] username;
	}
	username = new char[strlen(N) + 1];
	assert(username != NULL);
	strcpy(username, N);
}

void Admin::ChangeUsername(User& U, const char* N)
{
	User::changeUsername(U,N);
}