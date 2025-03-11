#include "Good.h"

/*
Good::Good(const string& prodName, const string& prodDescription, int prodRating, int prodSoldCount, const string& expDate, int qty) : 
Product(prodName, prodDescription, prodRating, prodSoldCount)
, expirationDate(expDate), quantity(qty) 
{
}
*/
// ^^^ Probably a redefinition

void Good::setExpirationDate(string expirationDate){
    expirationDate = this->expirationDate; 
};
        
void Good::setQuantity(int quantity){
    quantity = this->quantity;
};

string Good::getExpirationDate() const {
    return expirationDate;
}
    
string Good::getQuantity() const {
    return quantity;
}

void Good::getInfo() const {
    string expirationDate = getExpirationDate();
    string quantity = getQuantity();
    cout << "Expiration date: " << expirationDate << endl;
    cout << "Quantity: " << quantity << endl;
}
