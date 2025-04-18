// TO DO: #include all the standard libraries and your own libraries here
#ifndef VENDOR_H
    #define VENDOR_H 

#include <iostream>
#include <string>
#include "Product.h"
#include "Good.h"
#include "Media.h"
#include "./LinkedBagDS/LinkedBag.h"
#include "./LinkedBagDS/Node.h"
#include <memory>

using namespace std;

// To DO: define the class Vendor with the necessary functions and data fields
class Vendor {
    private:
        string username;
        string email;
        string password;
        string bio;
        string profilePicture;
        //LinkedBag<Product*> productList;
        LinkedBag<shared_ptr<Product>> productList;
        

    public:
        //Vendor(string username, string email, string password, string bio, string profile);
        Vendor();
        ~Vendor();
        Vendor(const Vendor& other);
        friend ostream& operator<<(ostream& os, Vendor& obj);
        friend istream& operator>>(istream& in, Vendor& obj);
        Vendor& operator=(const Vendor& other);
        void displayProfile();
        bool modifyPassword(string newPassword);
        bool createProduct(shared_ptr<Product> product, int k);
        void displayProduct(int k);
        void displayAllProducts();
        bool modifyProduct(int k);
        bool sellProduct(int k,int quantity);
        bool deleteProduct(int k);

        string getUsername();
        string getEmail();
        string getPassword();
        string getBio();
        string getProfilePicture();
        int getBagSize();

        // This is a function that allows you to compare two vendors based on their username and email address.
        // You may directly include it in your class definition. 
        // You don't need to modify it but will have to put it inside your class. 
        // Operator == overloading function prototype:
        bool operator==(const Vendor& otherVendor) const; 

    };



#endif