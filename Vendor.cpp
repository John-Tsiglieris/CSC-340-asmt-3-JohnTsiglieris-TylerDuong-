// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"
#include "Product.h"
#include "./LinkedBagDS/LinkedBag.h"
#include "./LinkedBagDS/Node.h"
#include <vector>
using namespace std;


Vendor::Vendor(string username, string email, string password, string bio, string profile){
	//productList = LinkedBag<Product>();
	this->username = username;
	this->email = email;
	this->password = password;
	this->bio = bio;
	this->profilePicture = profile;
}



Vendor::~Vendor()
{
}

void Vendor::displayProfile()
{
	cout << "Username: " << username << endl;
	cout << "Email Address: " << email << endl;
	cout << "Bio: " << bio << endl;
	cout << "Profile Picture: " << profilePicture << endl;
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

bool Vendor::createProduct(Product* product)
{
	cout << "Added " << product->getName() << " to list" << endl;
	productList.add(product);
	return true;
};

void Vendor::displayProduct(int k)
{
	Node<Product*>* node = productList.reverseFindKthItem(k);
	Product* product = node->getItem();
	product->display();
};

// Turns productList into a vector and iterates through it.
void Vendor::displayAllProducts()
{
	if (this->productList.getCurrentSize() > 0) {
		vector<Product*> productDisplay = productList.toVector();
		for (int i = 0; i < this->productList.getCurrentSize(); i++)
		{
			cout << "(DEBUG) Index: " << i << endl;
			cout << "Name: " << productDisplay[i]->getName() << endl;
			cout << "Description: " << productDisplay[i]->getDescription() << endl;
			cout << "Rating: " << productDisplay[i]->getRating() << endl;
			cout << "Sold Count: " << productDisplay[i]->getSoldCount() << endl;
			productDisplay[i]->getInfo();
		}
	} else {
		cout << "Empty bag!" << endl;
	}

}

bool Vendor::modifyProduct(int k)
{
	Node<Product*>* node = productList.reverseFindKthItem(k);
	Product* product = node->getItem();
	product->modify();
	return true;
}

bool Vendor::sellProduct(int k, int quantity)
{
	Node<Product*>* node = productList.reverseFindKthItem(k);
	Product* product = node->getItem(); 
	product->sell(quantity);
	return true;
}

bool Vendor::deleteProduct(int k)
{
	Node<Product*>* node = productList.reverseFindKthItem(k);
	Product* product = node->getItem();
	productList.remove(product); 
	delete product;
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
