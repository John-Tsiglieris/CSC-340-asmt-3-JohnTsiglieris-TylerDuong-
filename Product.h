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
        Product();
        Product(string name = NULL, string description = NULL, int rating = 0, int soldCount = 0);
        ~Product();
        friend ostream& operator<<(ostream& os, const Product& obj);
        friend istream& operator>>(istream& in, const Product& obj);
        void display();
        virtual bool modify();
        virtual void getInfo() const = 0; 
        virtual bool sell(int quantity) = 0;
        void setName(string& name);
        void setDescription(string& desc);
        void setRating(int inputRating);
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