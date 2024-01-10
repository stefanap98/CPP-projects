#include <iostream>
#include "Guardian.h"
#include "Warrior.h"
#include "Wizzard.h"


int main()
{
	Guardian g;
	g.print();
	std::cout << std::endl;

	Wizzard w;
	w.print();
	std::cout << std::endl;

	Warrior r;
	r.print();
	std::cout << std::endl;

	w.getattacked(60);
	w.print();
	std::cout << std::endl;

	r.getattacked(5);
	r.print();
	std::cout << std::endl;

	g.getattacked(8);
	g.print();

	return 0;
}