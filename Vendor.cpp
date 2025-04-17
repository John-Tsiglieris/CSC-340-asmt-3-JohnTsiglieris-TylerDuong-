// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"
#include "Product.h"
#include "./LinkedBagDS/LinkedBag.h"
#include "./LinkedBagDS/Node.h"
#include <vector>
#include <memory>
using namespace std;

#include <memory>
using namespace std;

/*
Vendor::Vendor(string username, string email, string password, string bio, string profile){
	this->username = username;
	this->email = email;
	this->password = password;
/*
Vendor::Vendor(string username, string email, string password, string bio, string profile){
	this->username = username;
	this->email = email;
	this->password = password;
	this->bio = bio;
	this->profilePicture = profile;
}
*/

Vendor::Vendor(){
}



Vendor::~Vendor()
{
}

// Copy constructor
Vendor::Vendor(const Vendor& other) {
	this->username = other.username;
	this->email = other.email;
	this->password = other.password;
	this->bio = other.bio;
	this->profilePicture = other.profilePicture;
	this->productList = other.productList;
}

Vendor& Vendor::operator=(const Vendor& other){
	if(this != &other){
		this->username = other.username;
	this->email = other.email;
	this->password = other.password;
	this->bio = other.bio;
	this->profilePicture = other.profilePicture;
	this->productList = other.productList;

	}
	return *this;
}

/**
 * Used to display all data members
 */
ostream& operator<<(ostream& os, Vendor& obj) {
	// Added colors because they're pretty
	os << "\033[1;32mUsername: \033[0m" << "\033[1;34m" << obj.username << "\033[0m~" << endl;
	os << "\033[1;32mEmail Address: " << "\033[1;34m" << obj.email<< "\033[0m" << endl;
	os << "\033[1;32mBio: " << "\033[1;34m" << obj.bio<< "\033[0m" << endl;
	os << "\033[1;32mProfile Picture: " << "\033[1;34m" << obj.profilePicture<< "\033[0m" << endl;
	return os;
}

/**
 * Used to create profile
 */
istream& operator>>(istream& in, Vendor& obj) {
	// Added colors because they're pretty
	cout << "Please input a username: " << endl;
	in >> obj.username;
	cout << "Please input an email: " << endl;
	in >> obj.email;
	cout << "Please input a password: " << endl;
	in >> obj.password;
	cout << "Please input a bio: " << endl;
	in >> obj.bio;
	cout << "Please input a profile picture (string): " << endl;
	in >> obj.profilePicture;
	return in;
}

bool Vendor::createProduct(std::shared_ptr<Product> product, int k)
{
	cout << "Added " << product->getName() << " to list" << endl;
	productList.add(product); // DEPRECATED
	//productList.appendK(move(product), k);
	//productList.appendK(product, k);
	return true;
};


bool Vendor::modifyPassword(string newPassword)
{
	if (newPassword.empty())
	{
		return false;
	}
	password = newPassword;
	cout << "New Password:" << password << endl;
	return true;
};

void Vendor::displayProduct(int k)
{
	Node<shared_ptr<Product> >* node = productList.reverseFindKthItem(k);
	shared_ptr<Product> product = node->getItem();
	cout << "\033[1;33mWARNING:\033[1;0m] Be aware this returns kth item from the END of the list" << endl;
	auto obj = product;

	if (auto a = std::dynamic_pointer_cast<Good>(obj)) {
		cout << *a;
	} else if (auto b = std::dynamic_pointer_cast<Media>(obj)) {
		cout << *b;
	}

};

// Turns productList into a vector and iterates through it.
void Vendor::displayAllProducts()
{
	if (this->productList.getCurrentSize() > 0) {
		vector<shared_ptr<Product>> productDisplay = productList.toVector();
		for (int i = 0; i < this->productList.getCurrentSize(); i++)
		{
			cout << "\033[1;33mIndex: " << "\033[1;34m" << i << "\033[0m" << endl;
			//cout << "Name: " << productDisplay[i]->getName() << endl;
			//cout << "Description: " << productDisplay[i]->getDescription() << endl;
			//cout << "Rati\\ng: " << productDisplay[i]->getRating() << endl;
			//cout << "Sold Count: " << productDisplay[i]->getSoldCount() << endl;

		auto obj = productDisplay[i];  // Current product

		// Dynamically cast obj to check for derived types
		if (auto a = std::dynamic_pointer_cast<Good>(obj)) {
			cout << *a;
		} else if (auto b = std::dynamic_pointer_cast<Media>(obj)) {
			cout << *b;
		}

		//productDisplay[i]->getInfo(); // Outputs base or overridden info
			
			//cout << *productDisplay[i];
		}
	} else {
		cout << "Empty bag!" << endl;
	}

}

bool Vendor::modifyProduct(int k)
{
	Node<shared_ptr<Product>>* node = productList.reverseFindKthItem(k);
	shared_ptr<Product> product = node->getItem();
	product->modify();
	return true;
}

bool Vendor::sellProduct(int k, int quantity)
{
	Node<shared_ptr<Product>>* node = productList.reverseFindKthItem(k);
	shared_ptr<Product> product = node->getItem(); 
	cout << "\033[1;31mDEBUG: \033[1;33m Printing product: \033[1;0m" << *product << endl;
	product->sell(quantity);
	return true;
}

bool Vendor::deleteProduct(int k)
{
	Node<shared_ptr<Product>>* node = productList.reverseFindKthItem(k);
	shared_ptr<Product> product = node->getItem();
	productList.remove(product); 
	//delete product; // no longer needed
	return true;
}

// Operator == overloading implementation
bool Vendor::operator==(const Vendor &otherVendor) const
{
	return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}

string Vendor::getUsername()
{
	return username;
}

string Vendor::getEmail()
{
	return email;
}

string Vendor::getPassword()
{
	return password;
}

string Vendor::getBio()
{
	return bio;
}

string Vendor::getProfilePicture()
{
	return profilePicture;
}

int Vendor::getBagSize() {
	return productList.getCurrentSize();
}
