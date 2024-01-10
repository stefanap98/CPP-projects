#pragma once
#ifndef STORE_H
#define STORE_H

//include product.h becase Store has Product in it
#include "Product.h"

class Store
{
	Product* arr;
	int capacity; //Maximum products in the store
	int size; //Current amount of products in the store
public:
	Store(int);//constructor
	~Store();//destructor
	void AddProduct(const Product&);
	void DeleteProduct(int);
	void ChangeProduct(int i);
	void DisplayProducts() const;
	int getSize() const;//get method
};

#endif /* STORE_H */