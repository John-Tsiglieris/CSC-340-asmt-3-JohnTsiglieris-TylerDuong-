#ifndef AMAZON340_H
	#define AMAZON340_H 

//#include "LinkedBagDS/LinkedBag.h" // Don't need since it's included in vendor
#include "Vendor.h"


 

// This class only contains a vendor
class Amazon340 {
	private:
		Vendor* vendor;

	public:
		Amazon340();
		~Amazon340();

		void createVendor(const std::string& username, const std::string& email, const std::string& password, const std::string& bio, const std::string& profilePicture);

		Vendor getVendor() const;
};

#endif