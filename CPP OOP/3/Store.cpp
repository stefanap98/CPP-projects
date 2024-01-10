#include "Store.h"
#include <iostream>
#include <cassert>
#include <iomanip>

using namespace std;

Store::Store(int cap)
{
	arr = new Product[cap];
	capacity = cap;
	size = 0;
}

Store::~Store()
{
	delete[capacity] arr;
}

void Store::AddProduct(const Product& p)
{
	assert(size < capacity);//I check the same thing with "if" before calling this function in main.cpp,but just to be sure i use assert here
	arr[size] = p;
	size++;
}

void Store::DeleteProduct(int i)
{
	if (i == size - 1)
	{
		size--;
	}
	else
	{
		for (int j = i; j < size - 1; j++)
		{
			arr[j] = arr[j + 1];
		}
		size--;
	}
}

void Store::ChangeProduct(int i)
{
	arr[i].read();
}

void Store::DisplayProducts() const
{
	cout << setw(10) << "Type of info: " << setw(10) << "Car" << setw(10) << "SKU" << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Category" << setw(10) << "Price" << setw(10) << "Count" << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << "Product [" << i << "] - ";
		arr[i].print();
	}
}

//i need getSize in order to check in main.cpp everytime before i call a functions regarding size and capacity
int Store::getSize() const
{
	return size;
}