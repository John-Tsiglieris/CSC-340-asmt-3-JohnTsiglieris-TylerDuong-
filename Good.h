#ifndef GOOD.H
#define GOOD.H
#include <string>
#include "Product.h"
using namespace std;

class Good : public Product {
    private:
        string expirationDate;
        int quantity;



    public:
    void setExpirationDate(string expirationDate);
    void setQuantity(int quantity);
};


#endif