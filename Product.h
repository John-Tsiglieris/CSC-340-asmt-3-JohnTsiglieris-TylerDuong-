// TO DO: #include all the standard libraries and your own libraries here
#ifndef PRODUCT.H
#define PRODUCT.H
#include <string>

// To DO: define the class Product with the necessary functions' prototypes and data fields


class Product {
    private:
        std::string name;
        std::string description;
        int rating;
        int soldCount;
    public:
        void display();
        bool modify();
        bool sell(int quantity);
        
        // This is a function that allows you to compare two products based on their name. 
        // You may directly include it in your class definition. 
        // You don't need to modify it but will have to put it inside your class. 
        // Operator overloading function prototype:
        bool operator==(const Product& otherProduct) const; 
        
};



#endif