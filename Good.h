#ifndef GOOD_H
#define GOOD_H
#include <string>
#include "Product.h"
using namespace std;

class Good : public Product {
    private:
        string expirationDate;
        int quantity;



    public:
    Good(const string& prodName, const string& prodDescription, int prodRating, int prodSoldCount, const string& expDate, int qty) : 
    Product(prodName, prodDescription, prodRating, prodSoldCount)
    , expirationDate(expDate), quantity(qty) 
    {
    }
    void setExpirationDate(string expirationDate);
    void setQuantity(int quantity);
    string getExpirationDate() const;
    string getQuantity() const;
    void getInfo();
};


#endif