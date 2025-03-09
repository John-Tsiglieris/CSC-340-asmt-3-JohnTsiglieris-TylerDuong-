#include "Good.h"

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

        void setExpirationDate(string expirationDate){
            expirationDate = this->expirationDate; 
        };
        
        void setQuantity(int quantity){
            quantity = this->quantity;
        };
    
};