#pragma once
#ifndef POWERUSER_H
#define POWERUSER_H
#include "User.h"

class PowerUser : virtual public User
{
public:
	PowerUser(const char* = "", const char* = "", const char* = "", const char* = "",int = 0);
	PowerUser(const PowerUser&);
	PowerUser& operator=(const PowerUser&);
	void print() const;
	void GiveReputation(const PowerUser&);
protected:
	char* getIp() const;
	void print_own() const;
private:
	int Reputation;
};

#endif // !POWERUSER_H
