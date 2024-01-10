#define _CRT_SECURE_NO_WARNINGS
#include "GameCharacter.h"
#include <iostream>
#include <cassert>

GameCharacter::GameCharacter(const char* n, int h, int m, int a, int d)
{
	CopyGC(n, h, m, a, d);
}

GameCharacter::GameCharacter(const GameCharacter& g)
{
	CopyGC(g.name, g.hp, g.mp, g.ap, g.dp);
}

void GameCharacter::CopyGC(const char* n, int h, int m, int a, int d)
{
	name = new char[strlen(n) + 1];
	assert(name != NULL);
	strcpy(name, n);
	hp = h;
	mp = m;
	ap = a;
	dp = d;
}

GameCharacter::~GameCharacter()
{
	DelGC();
}

void GameCharacter::DelGC()
{
	delete[] name;
}

GameCharacter& GameCharacter::operator=(const GameCharacter& g)
{
	if (this != &g)
	{
		DelGC();
		CopyGC(g.name, g.hp, g.mp, g.ap, g.dp);
	}
	return *this;
}

void GameCharacter::getattacked(int damage)
{
	if (damage > 0)
	{
		if (dp - damage < 0)
		{
			if (hp - damage > 0)
			{
				hp -= damage;
			}
			else
			{
				hp = 0;
			}
			
		}
	}
	else
	{
		std::cout << "Damage must be a positive number!" << std::endl;
	}
}

void GameCharacter::print() const
{
	std::cout << "Hero Stats" << std::endl;
	std::cout << "Name of hero: " << name << std::endl;
	std::cout << "Health: " << hp << std::endl;
	std::cout << "Magic:" << mp << std::endl;
	std::cout << "Attack:" << ap << std::endl;
	std::cout << "Deffence:" << dp << std::endl;
}