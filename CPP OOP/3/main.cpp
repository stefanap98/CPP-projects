#include <iostream>
#include "Store.h"

using namespace std;

int main() {
	char command;
	int cap;
	cout << "Enter capacity of Store: ";
	cin >> cap;
	//check if user entered a character
	if (!cin)
	{
		exit(1);
	}
	Store s = Store(cap);//or Store s(cap);
	int i =- 1;
	do
	{
		cout << "Enter command: ";
		cin >> command;

		switch (command)
		{
			case 'A':
			case 'a':
			{
				if (s.getSize() == cap)
				{
					cout << "Not enough capacity in the store!" << endl;
				}
				else
				{
					Product p;
					p.read();
					s.AddProduct(p);
				}
				break;
			}
			case 'X':
			case 'x':
			{

				cout << "Delete product: ";
				cin >> i;
				//check if user entered a character
				if (!cin)
				{
					exit(1);
				}
				if (i >= 0 && i < s.getSize())
				{
					s.DeleteProduct(i);
				}
				else
				{
					cout << "No such product!" << endl;
				}
				break;
			}
			case 'C':
			case 'c':
			{
				cout << "Change product: ";
				cin >> i;
				//check if user entered a character
				if (!cin)
				{
					exit(1);
				}
				if (i >= 0 && i < s.getSize())
				{
					s.ChangeProduct(i);
				}
				else
				{
					cout << "No such product!" << endl;
				}
				break;
			}
			case 'D':
			case 'd':
			{
				cout << "Display products: \n";
	
				if (s.getSize()>0)
				{
					s.DisplayProducts();
				}
				else
				{
					cout << "No products in the store!" << endl;
				}
				break;
			}
		}
		
	} while (command != 'Q' && command != 'q');

	return 0;
}
