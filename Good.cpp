#include "Good.h"
#include <iostream>
using namespace std;






Good::Good(const string& prodName, const string& prodDescription, int prodRating, int prodSoldCount, const string& expDate, int qty) : 
Product(prodName, prodDescription, prodRating, prodSoldCount), expirationDate(expDate), quantity(qty) 
{
}


ostream& operator<<(ostream& os, Good& obj) { //probably wrong check
	//os << "\033[1;32mProduct: \033[0m" << "\033[1;34m" << obj.prodName<< "\033[0m" << endl;
	//os << "\033[1;32mDescription: " << "\033[1;34m" << obj.prodDescription<< "\033[0m" << endl;
	//os << "\033[1;32mRating: " << "\033[1;34m" << obj.prodRating<< "\033[0m" << endl;
	//os << "\033[1;32mSoldCount: " << "\033[1;34m" << obj.prodSoldCount<< "\033[0m" << endl;
	os << "\033[1;32mExpiration Date: " << "\033[1;34m" << obj.getExpirationDate()<< "\033[0m" << endl;
	os << "\033[1;32mQuantity: " << "\033[1;34m" << obj.getQuantity()<< "\033[0m" << endl;
	return os;
	
}

string Good::getExpirationDate() const {
    return expirationDate;
}
    
int Good::getQuantity() const {
    return quantity;
}

void Good::getInfo() const {
    string expirationDate = getExpirationDate();
    int quantity = getQuantity();
    cout << "Expiration date: " << expirationDate << endl;
    cout << "Quantity: " << quantity << endl;
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
		<< "3. Type\n"
		<< "4. Expiration date\n"
		<< "5. Quantity\n"
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
		return false;
	}
	soldCount =+ k;
	this->quantity -= k;
	return true;
}