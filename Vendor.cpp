// TO DO: #include needed standard libraries and your own libraries here
#include "Vendor.h"
#include "Product.h"
#include "LinkedBag.h"

// TO DO: function implementations

class Vendor {
	private:
	    string username;
        string email;
        string password;
        string bio;
        string profilePicture;
		LinkedBag<Product> Vendor::productList;
	public:
		Vendor::Vendor() {

		}

		Vendor::~Vendor() {
		
		}

		void displayProfile(){
				cout << "Username: " << this->username << endl;	
				cout << "Email Address: " << this->email << endl;	
				cout << "Bio: " << this->bio << endl;	
				cout << "Profile Picture: " << this->profilePicture << endl;	

		} ;
        bool modifyPassword(string newPassword){
			if(newPassword.empty()){
				return false;
			}
			password = newPassword;
			cout << "New Password:" << password << endl;
			return true;
		};
        bool createProduct(Product product){
			cout << "Added " << product.getName() << " to list" << endl;
			productList.add(product);
		};
        void displayProduct(int k){
			productList.findKthItem(k);
		};

		template<class T>
        void displayAllProducts(){ 
			productList.display();							// NOT DONE, how to display LinkedBag?
		}

        bool modifyProduct(int k); // how do you modify product without sending any arguments?

        bool sellProduct(int k,int quantity){
			Product* product = productList.findKthItem(k);
			product.sell(quantity);
		};

        bool deleteProduct(int k){
			delete this;
		};

		// Operator == overloading implementation
		bool Vendor::operator==(const Vendor& otherVendor) const {
			return (Vendor::username == otherVendor.username) && (Vendor::email == otherVendor.email);
		}

		string getUsername (){
			return this->username;
		}
		string getEmail(){
			return this->email;
		}
		string password(){
			return this->password;
		}
		string bio(){
			return this->bio;
		}
		string profilePicture(){
			return this->profilePicture;
		}
		
		
		
};

