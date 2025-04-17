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

Product::Product(const Product& other){
	this->name =other.name;
	this->description= other.description;
	this->rating= other.rating;
	this->soldCount= other.soldCount;
}

Product& Product::operator=(const Product& other){
	if(this != &other){
		this->name =other.name;
	this->description= other.description;
	this->rating= other.rating;
	this->soldCount= other.soldCount;
	}
	return *this;
}

ostream& operator<<(ostream& os, const Product& obj) {
	//os << "\033[1;32mProduct: \033[0m" << "\033[1;34m" << obj.getName()<< "\033[0m" << endl;
	//os << "\033[1;32mDescription: " << "\033[1;34m" << obj.getDescription()<< "\033[0m" << endl;
	//os << "\033[1;32mRating: " << "\033[1;34m" << obj.getRating()<< "\033[0m" << endl;
	//os << "\033[1;32mSoldCount: " << "\033[1;34m" << obj.getSoldCount()<< "\033[0m" << endl;
	return os;
}


istream& operator>>(istream& in, Product& obj) {
	string name;
	string description;
	cout << "choose a name for the product" << endl;
	in >> name;
	obj.setName(name);
	cout << "write a description for the product" << endl;
	in >> description;
	obj.setDescription(description);
	//cout << "Choose what position k you would like to insert at: (integer)" << endl;
	//in >> k;
	return in;
}

//virtual void print(std::ostream& out) const = 0;  // pure virtual

		
// Deprecated function
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

void Product::setName(string& inputName) {
	name = inputName;
}

void Product::setDescription(string& inputDescription) {
	description = inputDescription;
}

void Product::setRating(int inputRating) {
	rating = inputRating;
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





