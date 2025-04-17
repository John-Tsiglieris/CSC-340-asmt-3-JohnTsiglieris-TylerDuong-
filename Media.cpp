#include "Media.h"
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;


Media::Media(const string& prodName, const string& prodDescription, int prodRating, int prodSoldCount, const string& type, string& targetAudience) : 
Product(prodName, prodDescription, prodRating, prodSoldCount), type(type), targetAudience(targetAudience) 
{
	
}

ostream& operator<<(ostream& os, Media& obj) { //probably wrong check
	os << "\033[1;32mType: " << "\033[1;34m" << obj.getType() << endl;
	os << "\033[1;32mTarget Audience: " << "\033[1;34m" << obj.getTargetAudience()<< "\033[0m" << endl;
	return os;
	
}

istream& operator>>(istream& in, Media& obj) {
	in >> static_cast<Product&>(obj);
	string type;
	string targetAudience;
	cout << "Input a type" << endl;
	in >> type;
	obj.setType(type);
	cout << "Input a target audience" << endl;
	in >> targetAudience;
	obj.setTargetAudience(targetAudience);
	return in;
}

string Media::getType() const{
    return type;
}

string Media::getTargetAudience() const {
    return targetAudience;
}

void Media::getInfo() const {
    string type = getType();
    string targetAudience = getTargetAudience();
    cout << "Media type: " << type << endl;
    cout << "Target Audience: " << getTargetAudience() << endl;
}

void Media::setName(string& inputName) {
    name = inputName;
}

void Media::setDescription(string& inputDesc) {
    description = inputDesc;
}

void Media::setType(string& inputType) {
    type = inputType;
}

void Media::setTargetAudience(string& inputAudience) {
    targetAudience = inputAudience;
}

bool Media::modify() {
    int vendorChoice = 0;
    cin >> vendorChoice;
    do {

		cout << "Choose what value to modify: \n"
		<< "1. Name\n"
		<< "2. Description\n"
		<< "3. Type\n"
		<< "4. Target Audience\n"
		<< "0. Logout\n"
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
				string type;
				cout << "Enter a new type: " << endl;
				cin >> type;
				setType(type);
				break;
			}
			case 4:{
				string audience;
				cout << "Enter a new target audience: " << endl;
				cin >> audience;
				setTargetAudience(audience);
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

bool Media::sell(int quantity) {
	if (quantity <= 0){
		return false;
	}
	soldCount =+ quantity;
	return true;
}
        
