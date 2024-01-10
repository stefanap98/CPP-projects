#pragma once
#ifndef WIZZARD_H
#define WIZZARD_H

#include "GameCharacter.h"

class Wizzard : public GameCharacter
{
public:
	Wizzard();
	Wizzard(const Wizzard&);
	Wizzard& operator=(const Wizzard&);
	void print() const;
private:
	GameCharacter guardian;
};

#endif // !WIZZARD_H