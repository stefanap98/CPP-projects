#pragma once
#ifndef MAGICBOX_H
#define MAGICBOX_H

const int MaxElements = 100;

template <class T>
class MagicBox
{
public:
	MagicBox(int);
	MagicBox(const MagicBox&);
	~MagicBox();
	MagicBox& operator=(const MagicBox&);
	void insert(T c);
	T pop();
	bool empty() const;
	bool full() const;
	void list() const;

private:
	T* Box;
	int top;
	int size;
	int Random(int) const;
};

#endif // !MAGICBOX_H
