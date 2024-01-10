#pragma once
#ifndef PRODUCT_H
#define PRODUCT_H

class Product //Product is a car
{
private:
	char* car; //Car name
	int SKU;
	char* Brand;
	char* Model;
	char* Category;
	double Price;
	int Count;
public:
	void read(); //fill in information about the products
	void print() const; //display products
	Product(); //constructor
};

#endif /* PRODUCT_H */
