#ifndef VENDOR_H
#define VENDOR_H

// TO DO: #include all the standard libraries and your own libraries here
#include <string>

// To DO: define the class Vendor with the necessary functions and data fields

class Vendor {
public:
    Vendor();
    ~Vendor(); //destructor
    // This is a function that allows you to compare two vendors based on their username and email address.  
    // You may directly include it in your class definition. 
    // You don't need to modify it but will have to put it inside your class. 
    // Operator == overloading function prototype:
    bool operator==(const Vendor& otherVendor) const; 


    private:
        std::string username;
        std::string email;

};

#endif