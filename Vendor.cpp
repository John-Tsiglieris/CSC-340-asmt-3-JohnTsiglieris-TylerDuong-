// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"
#include "Product.h"
#include "./LinkedBagDS/LinkedBag.h"
#include "./LinkedBagDS/LinkedBag.cpp"
#include "./LinkedBagDS/Node.h"
#include <vector>
using namespace std;

string username;
string email;
string password;
string bio;
string profilePicture;
LinkedBag<Product>* productList;

Vendor::Vendor(string username, string email, string password, string bio, string profile) {
	
}

Vendor::~Vendor() {

}

void Vendor::displayProfile(){
		cout << "Username: " << username << endl;	
		cout << "Email Address: " << email << endl;	
		cout << "Bio: " << bio << endl;	
		cout << "Profile Picture: " << profilePicture << endl;	

} ;

bool Vendor::modifyPassword(string newPassword){
	if(newPassword.empty()){
		return false;
	}
	password = newPassword;
	cout << "New Password:" << password << endl;
	return true;
};

bool Vendor::createProduct(Product product){
	cout << "Added " << product.getName() << " to list" << endl;
	productList.add(product);
	return true;
};

void Vendor::displayProduct(int k){
	productList.reverseFindKthItem(k);
};


		
void Vendor::displayAllProducts(){ 
	std::vector<Product> productDisplay = productList.toVector();
	for(const Product& product : productDisplay)	{
		productDisplay.displayProduct();

	}		// NOT DONE, how to display LinkedBag?
}

bool Vendor::modifyProduct(int k) {

} // how do you modify product without sending any arguments?

bool Vendor::sellProduct(int k,int quantity){
	Node<Product>* node/*Product& product*/ = productList->reverseFindKthItem(k);
	Product product = node->getItem();
	//product.sell(quantity);
};

bool Vendor::deleteProduct(int k){
	delete this;
};

// Operator == overloading implementation
bool Vendor::operator==(const Vendor& otherVendor) const {
	return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
}

string Vendor::getUsername (){
	return username;
}

string Vendor::getEmail(){
	return email;
}

string Vendor::getPassword(){
	return password;
}

string Vendor::getBio(){
	return bio;
}

string Vendor::getProfilePicture(){
	return profilePicture;
}
		
	

