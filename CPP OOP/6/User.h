#pragma once
#ifndef USER_H
#define USER_H

#include "Guest.h"

class User : public Guest
{
public:
	User(const char* = "", const char* = "", const char* = "", const char* = "");
	User(const User&);
	~User();
	User& operator=(const User&);
	void print() const;
	void setNewPassword(const char* , const char*);
	char* getIp() const;
protected:
	void changeUsername(User&,const char*);
	void print_own() const;
	char* username;
	char* title;
private:
	char* password;
	void Copy(const char* , const char* );
	void Del();
	char* encrypt(const char*);//XOR encryption from GeeksForGeeks,some of the other encryptions needed <string> library which isnt allowed in the homework...
};

#endif // !USER_H
