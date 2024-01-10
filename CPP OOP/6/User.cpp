#define _CRT_SECURE_NO_WARNINGS
#include "User.h"
#include <cstring>
#include <cassert>
#include <iostream>

const int MAXCHAR = 100;

char* User::encrypt(const char* pass)
{
	int len = strlen(pass);

	char* EncPass = new char[len + 1];
	assert(EncPass != NULL);
	strcpy(EncPass, pass);

	char xorKey = 'P';

	for (int i = 0; i < len; i++)
	{
		EncPass[i] = EncPass[i] ^ xorKey;
	}

	return EncPass;
}

User::User(const char* IP, const char* UN,const char* PW, const char* T) : Guest(IP)
{
	password = new char[strlen(PW) + 1];
	assert(password != NULL);
	strcpy(password, encrypt(PW));
	Copy(UN, T);
}

User::User(const User& u) : Guest(u)
{
	Copy(u.username, u.title);
	password = new char[strlen(u.password) + 1];
	assert(password != NULL);
	strcpy(password, u.password);
}

User::~User()
{
	Del();
}

User& User::operator=(const User& u)
{
	if (this != &u)
	{
		Guest::operator=(u);
		Del();
		Copy(u.username, u.title);
		password = new char[strlen(u.password) + 1];
		assert(password != NULL);
		strcpy(password, u.password);
	}
	return *this;
}

void User::print() const
{
	Guest::print();
	print_own();
}

void User::print_own() const
{
	std::cout << "Username: " << username << std::endl;
	//std::cout << "Password: " << password << std::endl; Not sure if you need this. Either way it will print the crypted password not the real one
	std::cout << "Title: " << title << std::endl;
}

void User::setNewPassword(const char* OLD,const char* NEW)
{
	
	if (strcmp(password, encrypt(OLD)) != 0)
	{
		std::cout << "Wrong Password" << std::endl;
	}
	else
	{
		std::cout << "Correct.Your password will be changed" << std::endl;

		if (password != NULL)
		{
			delete[] password;
		}
		
		password = new char[strlen(NEW) + 1];
		assert(password != NULL);
		strcpy(password, encrypt(NEW) );
	}
	
}

void User::Copy(const char* UN, const char* T)
{
	username = new char[strlen(UN) + 1];
	assert(username != NULL);
	strcpy(username, UN);

	title = new char[strlen(T) + 1];
	assert(title != NULL);
	strcpy(title, T);
}

void User::Del()
{
	delete[] username;
	delete[] password;
	delete[] title;
}

char* User::getIp() const
{
	return Guest::getIp();
}

void User::changeUsername(User& U,const char* N)
{
	if (U.username != NULL)
	{
		delete[] U.username;
	}
	U.username = new char[strlen(N) + 1];
	assert(U.username != NULL);
	strcpy(U.username, N);
}