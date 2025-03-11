// TO DO: Implementation of Amazon340 functions
#include <iostream>
#include <string>
#include "Amazon340.h"
using namespace std;

Vendor* vendor;
		 


Amazon340::Amazon340() {
	
}
		
//Amazon340::~Amazon340() { // maybe not needed since it's not in heap
	
//}

void Amazon340::createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture){
	// make new vendor object
	vendor = new Vendor( username, email, password, bio, profilePicture);
}

Vendor Amazon340::getVendor() const{
	return *this->vendor;

}


