#include "Product.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int MAXCHAR = 100;//constant for maximum characters

Product::Product()
{
	car = new char[MAXCHAR];
	Brand = new char[MAXCHAR];
	Model = new char[MAXCHAR];
	Category = new char[MAXCHAR];
}

void Product::read()
{
	cout << "Car: "; cin >> car;
	cout << "SKU: "; cin >> SKU;
	//check if user entered a character
	if (!cin)
	{
		exit(1);
	}
	cout << "Brand: "; cin >> Brand;
	cout << "Model: "; cin >> Model;
	cout << "Category: "; cin >> Category;
	cout << "Price: "; cin >> Price;
	//check if user entered a character
	if (!cin)
	{
		exit(1);
	}
	cout << "Count: "; cin >> Count;
	//check if user entered a character
	if (!cin)
	{
		exit(1);
	}
}

void Product::print()const
{
	cout << setw(10) << car << setw(10) << SKU << setw(10) << Brand << setw(10) << Model << setw(10) << Category << setw(10) << Price << setw(10) << Count << "\n";
}

