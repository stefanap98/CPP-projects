#pragma once
#ifndef INTSTACK_H
#define INTSTACK_H

const int MaxStack = 100;//Maximalen broi elementi na steka
const int FullStack = MaxStack;//kontstanta pokazvashta dali steka e pylen
const int EmptyStack = -1;//konstanta pokazvashta dali steka e prazen

class IntStack {
private:
	int Stack [MaxStack];//stek
	int top;//ukazatel kym vyrha
public:
	IntStack();//constructor po podrazbirane
	IntStack(const IntStack&);//copy constructor
	void read();//vkarvane na chisla v steka prez konzolata
	bool isFull() const;//funkciq proverqvashta dali steka e pylen
	bool isEmpty() const;//funkciq proverqvashta dali steka e prazen
	void print() const;//funkciq izkarvashta sydyrjanieto na steka 
	void push(int);//rychno vkarvane na chisla v steka
	int pop();//vryshta chisloto koeto e nai-gore v steka i go izvajda ot nego
	void peek() const;//izvejda na konzolata chisloto koeto e nai-gore v steka bez da go vadi ot nego
	IntStack& operator=(const IntStack&);//predefiniran operator za ravenstva mejdu dva steka
	friend IntStack& SortStack(IntStack& st);//vynshna priqtelska funkciq za sortirane na steka v nizhodqsht red
	//definirana e kato friend za da ima dostyp do chlen dannite na klasa,tyi kato e vynshna funkciq
};


#endif /* IntStack_H */
