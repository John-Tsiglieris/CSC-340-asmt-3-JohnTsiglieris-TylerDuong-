// TO DO: #include all the standard libraries and your own libraries here
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;

// TO DO: function implementations

// ------------------------------------------------------------------------------
// Operator overloading implementation


class Product {
	protected:
		string name;
        string description;
        int rating;
        int soldCount;
		

	public:
		void display() {
			cout << "Product name: " << name << endl;
			cout << "Product description: " << description << endl;
			cout << "Product rating: " << rating << endl;
			cout << "Amount of product sold: " << soldCount << endl;
		}

		bool modify() { // dont know if it is correct - Tyler.
			
			return true;
		}


		bool sell(int quantity) { // Correct .. ? - Tyler
			if (quantity <= 0){
				return false;
			}
			soldCount =+ quantity;
			return true;
		}
		bool Product::operator==(const Product& otherProduct) const {
	return Product::name == otherProduct.name;
}
	string getName() {
        return this->name;
        }

	string getDescription(){
		return this->description;
	}

	int getRating(){
		return this->rating;
	}

	int getsoldCount(){
		return this->soldCount;
	}
};




