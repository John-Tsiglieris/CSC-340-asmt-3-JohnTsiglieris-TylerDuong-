// TO DO: #include all the standard libraries and your own libraries here
#ifndef VENDER.H
#define VENDER.H
#include <iostream>
#include <string>

// To DO: define the class Vendor with the necessary functions and data fields
class Vendor {
    private:
        std::string username;
        std::string email;
        std::string password;
        std::string bio;
        std::string profilePicture;

    public:
        void displayProfile();
        bool modifyPassword(std::string newPassword);
        bool createProduct(product Product);
        void displayProduct(int k);
        bool modifyProduct(int k);
        bool sellProduct(int k,int quantity);
        bool deleteProduct(int k);
        bool operator==(const Vendor& otherVendor) const; 







    };
// This is a function that allows you to compare two vendors based on their username and email address.
// You may directly include it in your class definition. 
// You don't need to modify it but will have to put it inside your class. 
// Operator == overloading function prototype:


#endif