#pragma once
#ifndef WARRIOR_H
#define WARRIOR_H

#include "GameCharacter.h"

class Warrior : public GameCharacter
{
public:
	Warrior();
	Warrior(const Warrior&);
	Warrior& operator=(const Warrior&);
	void print() const;
private:
	GameCharacter guardian;
};

#endif // !WARRIOR_H