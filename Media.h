#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include "Product.h"
using namespace std;

class Media : public Product {
    private:
        string type;
        string targetAudience;




    public: 
        Media(const string& prodName, const string& prodDescription, int prodRating, int prodSoldCount, const string& type, string& targetAudience);
        friend ostream& operator<<(ostream& os, Media& obj);
        friend istream& operator>>(istream& in, Media& obj);
        string getType() const;
        string getTargetAudience() const;
        void setName(string& name);
        void setDescription(string& desc);
        void setType(string& type);
        void setTargetAudience(string& targetAudience);
        void getInfo() const;
        bool modify();
        bool sell(int k);
        
};

#endif