#include "Good.h"

string expirationDate;
int quantity;


Good::Good(const string& prodName, const string& prodDescription, int prodRating, int prodSoldCount, const string& expDate, int qty) : 
Product(prodName, prodDescription, prodRating, prodSoldCount)
, expirationDate(expDate), quantity(qty) 
{
}

void Good::setExpirationDate(string expirationDate){
    expirationDate = this->expirationDate; 
};
        
void Good::setQuantity(int quantity){
    quantity = this->quantity;
};
    
