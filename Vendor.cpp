// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"

// TO DO: function implementations

Vendor::Vendor() {

}

Vendor::~Vendor() {
	
}

// Operator == overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
	return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}
