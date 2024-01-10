#pragma once
#ifndef GUARDIAN_H
#define GUARDIAN_H

#include "GameCharacter.h"

class Guardian : public GameCharacter
{
public:
	Guardian();
	Guardian(const Guardian&);
	Guardian& operator=(const Guardian&);
	void print() const;
private:
	GameCharacter guardian;
};

#endif // !GUARDIAN_H