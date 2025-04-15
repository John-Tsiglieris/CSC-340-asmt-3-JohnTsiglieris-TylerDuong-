// TO DO: Implementation of Amazon340 functions
#include <iostream>
#include <string>
#include "Amazon340.h"
using namespace std;


		 


Amazon340::Amazon340() {
	
}
		
Amazon340::~Amazon340() {
	
}

ostream& operator<<(ostream& os, const Amazon340& obj) {
	cout << "Welcome to Amazon340!" << endl;
	return os;
}


void Amazon340::createVendor(){
	// make new vendor object
	vendor = new Vendor();
	cin >> *vendor;
}

Vendor Amazon340::getVendor() const{
	return *this->vendor;

}


