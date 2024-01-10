#pragma once
#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

class GameCharacter
{
public:
	void getattacked(int);
	GameCharacter(const char* = "",int = 0,int = 0,int = 0,int = 0);
	GameCharacter(const GameCharacter&);
	~GameCharacter();
	GameCharacter& operator=(const GameCharacter&);
	void print() const;
	
private:
	char* name;
	int hp;
	int mp;
	int ap;
	int dp;
	void CopyGC(const char*, int , int , int , int );
	void DelGC();
};

#endif // !GAMECHARACTER_H
