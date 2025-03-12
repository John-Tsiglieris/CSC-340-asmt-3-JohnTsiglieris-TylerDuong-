#include <string>
#include <iostream>
#include "Product.h"
using namespace std;


// ------------------------------------------------------------------------------
// Operator overloading implementation


Product::Product(string name, string description, int rating, int soldCount) : name(name), description(description) {
}

Product::~Product()
{
}

		

void Product::display() {
	cout << "Product name: " << name << endl;
	cout << "Product description: " << description << endl;
	cout << "Product rating: " << rating << endl;
	cout << "Amount of product sold: " << soldCount << endl;
}

bool Product::modify() { // dont know if it is correct - Tyler.
	
	return true;
}


bool Product::sell(int quantity) { // Correct .. ? - Tyler
	if (quantity <= 0){
		return false;
	}
	soldCount =+ quantity;
	return true;
}

bool Product::operator==(const Product& otherProduct) const {
	return Product::name == otherProduct.name;
}

string Product::getName() {
	return name;
}

string Product::getDescription(){
	return description;
}

int Product::getRating(){
	return rating;
}

int Product::getSoldCount(){
	return soldCount;
}





