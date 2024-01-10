#pragma once
#ifndef ADMIN_H
#define ADMIN_H
#include "PowerUser.h"
#include "Vip.h"

class Admin : public PowerUser, public Vip
{
public:
	Admin(const char* = "", const char* = "", const char* = "", const char* = "", int = 0);
	Admin(const Admin&);
	Admin& operator=(const Admin&);
	void print() const;
	void ChangeOwnUsername(const char* );
	void ChangeUsername(User& , const char*);
protected:
	void print_own() const;
};

#endif // !ADMIN_H
