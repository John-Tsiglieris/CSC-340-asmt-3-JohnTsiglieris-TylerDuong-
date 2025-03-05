// TO DO: #include all the standard libraries and your own libraries here
#include <string>
#include <iostream>
#include "Product.h"
// TO DO: function implementations

// ------------------------------------------------------------------------------
// Operator overloading implementation


class Product {
	private:
		std::string name;
        std::string description;
        int rating;
        int soldCount;

	public:
		void display() {
			std:: cout << "Product name: " << name << std::endl;
			std:: cout << "Product description: " << description << std::endl;
			std:: cout << "Product rating: " << rating << std::endl;
			std:: cout << "Amount of product sold: " << soldCount << std::endl;
		}

		bool modify() {

		}

		bool sell(int quantity) {
			
		}
		bool Product::operator==(const Product& otherProduct) const {
	return Product::name == otherProduct.name;
}
};




