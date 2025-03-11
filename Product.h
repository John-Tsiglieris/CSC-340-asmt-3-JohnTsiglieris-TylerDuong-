#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

// To DO: define the class Product with the necessary functions' prototypes and data fields


class Product {
    protected:
        string name;
        string description;
        int rating;
        int soldCount;
    public:
        Product(string name, string description, int rating = 0, int soldCount = 0);
        ~Product();
        void display();
        bool modify();
        bool sell(int quantity);
        string getName();
        string getDescription();
        int getRating();
        int getSoldCount();
        
        // This is a function that allows you to compare two products based on their name. 
        // You may directly include it in your class definition. 
        // You don't need to modify it but will have to put it inside your class. 
        // Operator overloading function prototype:
        bool operator==(const Product& otherProduct) const; 

        
        
};



#endif