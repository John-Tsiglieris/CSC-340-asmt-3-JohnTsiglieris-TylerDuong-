#include "Media.h"
#include <string>
#include <iostream>
#include "Product.h"
using namespace std;



string Media::getType() const{
    return type;
}

string Media::getTargetAudience() const {
    return targetAudience;
}

void Media::getInfo() const {
    string type = getType();
    string targetAudience = getTargetAudience();
    cout << "Media type: " << type << endl;
    cout << "Target Audience: " << getTargetAudience() << endl;
}
        
