#include "Good.h"

class Good : public Product {
    private:
        string expirationDate;
        int quantity;

    public:
        Good(const string& prodName, const string& prodDescription, int prodRating, int prodSoldCount, const string& expDate, int qty) : Product()
        , expirationDate(expDate), quantity(qty) {
            name = prodName;
            description = prodDescription;
            rating = prodRating;
            soldCount = prodSoldCount;
        }
        void setExpirationDate(string expirationDate){
            expirationDate = this->expirationDate; 
        };
        void setQuantity(int quantity){
            quantity = this->quantity;
        };
    
};