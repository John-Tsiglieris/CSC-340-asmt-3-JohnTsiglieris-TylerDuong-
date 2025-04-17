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

ostream& operator<<(ostream& os, const Product& obj) {
	os << "\033[1;32mProduct: \033[0m" << "\033[1;34m" << obj.name<< "\033[0m" << endl;
	os << "\033[1;32mDescription: " << "\033[1;34m" << obj.description<< "\033[0m" << endl;
	os << "\033[1;32mRating: " << "\033[1;34m" << obj.rating<< "\033[0m" << endl;
	os << "\033[1;32mSoldCount: " << "\033[1;34m" << obj.soldCount<< "\033[0m" << endl;
	return os;
}

istream& operator>>(istream& in, const Product& obj) {
	cout << "choose a name for the product" << endl;
	in >> obj.name;
	cout << "write a description for the product" << endl;
	in >> obj.description;
	//cout << "Choose what position k you would like to insert at: (integer)" << endl;
	//in >> k;
	return in;
}

		

void Product::display() {
	cout << "Product name: " << name << endl;
	cout << "Product description: " << description << endl;
	cout << "Product rating: " << rating << endl;
	cout << "Amount of product sold: " << soldCount << endl;
}

bool Product::modify() {
	
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





