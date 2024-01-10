#pragma once
#ifndef VIP_H
#define VIP_H
#include "User.h"

class Vip : virtual public User
{
public:
	Vip(const char* = "", const char* = "", const char* = "", const char* = "");
	Vip(const Vip&);
	Vip& operator=(const Vip&);
	void print() const;
	void changeTitle(const char*);
protected:
	void print_own() const;
};

#endif // !VIP_H
