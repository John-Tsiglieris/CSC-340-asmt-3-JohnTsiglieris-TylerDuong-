#include "Good.h"
#include <iostream>
using namespace std;

Good::Good() : Product("", "", 0, 0), expirationDate(""), quantity(0) 
{
}

Good::Good(const string& prodName, const string& prodDescription, int prodRating, int prodSoldCount, const string& expDate, int qty) : 
Product(prodName, prodDescription, prodRating, prodSoldCount), expirationDate(expDate), quantity(qty) 
{
}

Good::~Good()
{
}

//Copy Constructor
Good::Good(const Good& other): Product(other), expirationDate(other.expirationDate), quantity(other.quantity) {

}

Good& Good::operator=(const Good& other) {
	if(this != &other){
		this->expirationDate = other.expirationDate;
		this->quantity= other.quantity;
	}
	return *this;
}

ostream& operator<<(ostream& os, Good& obj) {
	os << "\033[1;32mProduct Name: \033[0m" << "\033[1;34m" << obj.getName()<< "\033[0m" << endl;
	os << "\033[1;32mDescription: " << "\033[1;34m" << obj.getDescription()<< "\033[0m" << endl;
	os << "\033[1;32mRating: " << "\033[1;34m" << obj.getRating()<< "\033[0m" << endl;
	os << "\033[1;32mSoldCount: " << "\033[1;34m" << obj.getSoldCount()<< "\033[0m" << endl;
	os << "\033[1;32mExpiration Date: " << "\033[1;34m" << obj.getExpirationDate()<< "\033[0m" << endl;
	os << "\033[1;32mQuantity: " << "\033[1;34m" << obj.getQuantity()<< "\033[0m" << endl;
	return os;
	
}

istream& operator>>(istream& in, Good& obj) {
	in >> static_cast<Product&>(obj);
	string expirationDate;
	int quantity;
	cout << "Input an expiration date" << endl;
	in >> expirationDate;
	obj.setExpirationDate(expirationDate);
	cout << "Input a quantity" << endl;
	in >> quantity;
	obj.setQuantity(quantity);
	return in;
}


string Good::getExpirationDate() const {
    return expirationDate;
}
    
int Good::getQuantity() const {
    return quantity;
}

void Good::getInfo() const {
    //string expirationDate = getExpirationDate();
    //int quantity = getQuantity();
    //cout << "Expiration date: " << expirationDate << endl;
    //cout << "Quantity: " << quantity << endl;
	cout << *this;
}

void Good::setName(string& inputName) {
    name = inputName;
}

void Good::setDescription(string& inputDesc) {
    description = inputDesc;
}

void Good::setExpirationDate(string& exp) {
    expirationDate = exp;
}

void Good::setQuantity(int qty) {
    quantity = qty;
}


bool Good::modify() {
    int vendorChoice;
    do {

		cout << "Choose what value to modify: \n"
		<< "1. Name\n"
		<< "2. Description\n"
		<< "3. Expiration date\n"
		<< "4. Quantity\n"
		<< "0. Exit\n"
		<< "Choice: ";
		cin >> vendorChoice;

		switch (vendorChoice) {
			case 1:{
                string name;
				cout << "Enter a new name: " << endl;
                cin >> name;
                setName(name);
				break;
			}
			case 2: {
				string description;
				cout << "Enter a new description: " << endl;
				cin >> description;
				setDescription(description);
				break;
			}
			case 3: {
				string exp;
				cout << "Enter a new expiraiton date: " << endl;
				cin >> exp;
				setExpirationDate(exp);
				break;
			}
			case 4:{
				int qty;
				cout << "Enter a new quantity: " << endl;
				cin >> qty;
				setQuantity(qty);
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (vendorChoice != 0);
    return true;
}

bool Good::sell(int k) {
	if (k <= 0 || k > this->quantity){
		cout << "Not enough goods to sell!" << endl;
		return false;
	}

	soldCount += k;
	this->quantity -= k;
	cout << "Selling " << k << " goods!" << endl;
	cout << "New sold count: " << soldCount << endl;
	cout << "New quantity: " << quantity << endl;
	return true;
}