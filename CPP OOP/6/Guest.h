#pragma once
#ifndef GUEST_H
#define GUEST_H

class Guest
{
public:
	Guest(const char* = "");
	Guest(const Guest&);
	~Guest();
	Guest& operator=(const Guest&);
	void print() const;
	char* getIp() const;
protected:
	void print_own() const;
private:
	char* ip;
	void Copy(const char*);
	void Del();
};


#endif // !GUEST_H
