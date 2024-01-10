#include <iostream>
#include <random>
#include "MagicBox.h"
#include "MagicBox.cpp"

int main()
{
	std::cout << "How much people are in the pub?" << std::endl;
	int x;
	do {
		std::cin >> x;
	} while (x <= 0);
	MagicBox<int> m(x);
	m.insert(2);
	m.insert(3);
	m.insert(4);
	m.list();
	std::cout << std::endl;

	MagicBox<int> p(x);
	p = m;
	p.list();
	std::cout << std::endl;

	MagicBox<int> q = p;
	q.pop();
	q.list();
	std::cout << std::endl;

	std::cout << "Out from the box came: " << m.pop() << std::endl;
	m.list();
	std::cout << std::endl;

	std::cout << "Out from the box came: " << m.pop() << std::endl;
	m.list();
	std::cout << std::endl;

	std::cout << "Out from the box came: " << m.pop() << std::endl;
	m.list();
	std::cout << std::endl;

	std::cout << "Out from the box came: " << m.pop() << std::endl;
	m.list();
	std::cout << std::endl;

	return 0;
}