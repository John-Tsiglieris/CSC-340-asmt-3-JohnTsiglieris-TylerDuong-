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
        Good();
        ~Good();
        Good(const Good& other);
        Good(const string& prodName, const string& prodDescription, int prodRating, int prodSoldCount, const string& expDate, int qty);
        friend ostream& operator<<(ostream& os, Good& obj);
        friend istream& operator>>(istream& in, Good& obj);
        Good& operator=(const Good& other);
        string getExpirationDate() const;
        int getQuantity() const;
        void getInfo() const;
        void setName(string& name);
        void setDescription(string& desc);
        void setExpirationDate(string& exp);
        void setQuantity(int qty);
        bool modify();
        bool sell(int k);
};


#endif