#include "PowerUser.h"
#include <iostream>

PowerUser::PowerUser(const char* IP, const char* UN, const char* PW,const char* T, int REP) : User(IP,UN,PW,T)
{
	Reputation = REP;
}

PowerUser::PowerUser(const PowerUser& pu) : User(pu)
{
	Reputation = pu.Reputation;
}

PowerUser& PowerUser::operator=(const PowerUser& pu)
{
	if (this != &pu)
	{
		User::operator=(pu);
		Reputation = pu.Reputation;
	}
	return *this;
}

void PowerUser::print() const
{
	User::print();
	print_own();
}

void PowerUser::print_own() const
{
	std::cout << "Reputation: " << Reputation << std::endl;
}

void PowerUser::GiveReputation(const PowerUser& pu)
{
	if (username == pu.username && (getIp() == pu.getIp()) )
	{
		std::cout << "You can't +REP yourself! " << std::endl;
	}
	else
	{
		++Reputation;
	}
}

char* PowerUser::getIp() const
{
	return User::getIp();
}