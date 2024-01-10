#include "IntStack.h"
#include <iostream>

using namespace std;

IntStack::IntStack()
{
	top = EmptyStack;
}

IntStack::IntStack(const IntStack& p)
{
	top = p.top;
	for (int i = 0; i <= top; i++)
	{
		Stack[i] = p.Stack[i];
	}
}

bool IntStack::isFull() const
{
	return top == FullStack;
}

bool IntStack::isEmpty() const
{
	return top == EmptyStack;
}

void IntStack::print() const
{
	cout << "Stack numbers:" << endl;
	for (int i = top; i >= 0; i--)
	{
		cout << Stack[i] << endl;
	}
}

void IntStack::push(int p)
{
	if (!isFull())
	{
		Stack[++top] = p;
	}
	else
	{
		cout << "FULLSTACK!"<<endl;
	}
}

void IntStack::read()
{
	//proverka dali e vyvedeno pravilno chislo
	int x;
	do {
		cout << "How many numbers are you gonna type: ";
		cin >> x;
		if (!cin)
		{
			cout << "Thats not a number...";
			exit(1);
		}
	} while (x <= 0);
	cout << "Enter numbers:";
	int a;
	for (int i = 0; i < x; i++)
	{
		if (!isFull())
		{
			cin >> a;
			Stack[i] = a;
			top++;
		}
		else
		{
			cout << "FullStack!" << endl;
			return;
		}
	}
}

int IntStack::pop()
{
	if (!isEmpty())
	{
		return Stack[top--];
	}
	else
	{
		cout << "EmptyStack!" << endl;
		return 0;
	}
}

void IntStack::peek() const
{
	if (!isEmpty())
	{
		cout << Stack[top];
	}
	else
	{
		cout << "EmptyStack!" << endl;
	}
}


IntStack& IntStack::operator=(const IntStack& p)
{
	if (this != &p)
	{
		top = p.top;
		for (int i = 0; i <= top; i++)
		{
			Stack[i] = p.Stack[i];
		}
	}
	return *this;
}

IntStack& SortStack(IntStack& st)
{
	int min;
	int x=0;
	for (int i = 0; i < st.top; i++)
	{
		min = st.Stack[i];
		x = i;
		for (int j = i + 1; j < st.top+1; j++)
		{
			if (min > st.Stack[j])
			{
				min = st.Stack[j];
				x = j;
			}
		}
		st.Stack[x] = st.Stack[i];
		st.Stack[i] = min;
	}

	return st;
}