#include "Media.h"
#include <string>
#include "Product.h"
using namespace std;

class Media : public Product {
    private:
        string type;
        string targetAudience;




    public:

        string getType(){
            return this->type;
        }
        string getTargetAudience(){
            return this->targetAudience;
        }
};      
        
