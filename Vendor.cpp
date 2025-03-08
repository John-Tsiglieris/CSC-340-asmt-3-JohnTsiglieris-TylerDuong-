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
		LinkedBag<Product> productList;
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
        void displayAllProducts();
        bool modifyProduct(int k);
        bool sellProduct(int k,int quantity);
        bool deleteProduct(int k);

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

