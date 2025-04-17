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
		Amazon340(const Amazon340& other);

		friend ostream& operator<<(ostream& os, const Amazon340& obj);

		Amazon340& operator=(const Amazon340& other);

		void createVendor();

		Vendor getVendor() const;
};

#endif