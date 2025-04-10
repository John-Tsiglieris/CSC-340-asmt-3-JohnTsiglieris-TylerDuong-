#include <iostream> 
#include <string>

// TO DO: #include any other libraries you need
#include "Amazon340.h"
//#include "Vendor.h"


using namespace std;

/** 
 * 
 * Displays the application's main menu
 * pre create a new object of type Vendor
 * @param vendor object to interact with
 * 
 * */

void displayVendorMenu(Vendor& vendor){
	int vendorChoice = 0;
	do {

		cout << "\n Hi, "<< vendor.getUsername() <<", what would you like to do:\n"
		<< "1. Display Profile\n"
		<< "2. Modify Password\n"
		<< "3. Create Product\n"
		<< "4. Display All Products\n"
		<< "5. Display Kth Product\n"
		<< "6. Modify Product\n"
		<< "7. Sell Product\n"
		<< "8. Delete Product\n"
		<< "0. Logout\n"
		<< "Choice: ";
		cin >> vendorChoice;

		switch (vendorChoice) {
			case 1:{
				// TO DO: display vendor's profile information
				//      : e.g. vendor.displayProfile();
				cout << "case 1" << endl;
				vendor.displayProfile();
				break;
			}
			case 2: {
				// TO DO: ask for new password and update vendor's password
				string password;
				cout << "Input a new password: " << endl;
				cin >> password;
				vendor.modifyPassword(password);
				break;
			}
			case 3: {
				// Create the product and add it to the vendor's products
				int productType;
				string name;
				string description;
				int rating = 0;
				int sold = 0;

				cout << "choose a product type: (1 = good) (2 = media)" << endl;
				cin >> productType;
				cout << "choose a name for the product" << endl;
				cin >> name;
				cout << "write a description for the product" << endl;
				cin >> description;

				if (productType == 1) {
					string exp;
					int qty;
					cout << "Set an expiration date" << endl;
					cin >> exp;
					cout << "Enter a quantity:" << endl;
					cin >> qty;
					unique_ptr<Product> product(new Good(name, description, rating, sold, exp, qty));
					vendor.createProduct(std::move(product));
				} else if (productType == 2) {
					string type;
					string targetAudience;
					unique_ptr<Product> product(new Media(name, description, rating, sold, type, targetAudience));
					vendor.createProduct(std::move(product));
				}
				break;
			}
			case 4:{
				vendor.displayAllProducts();
				break;
			}
			case 5: {
				// Find the Kth product, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				int k;
				cout << "please enter a value k for kth product: " << endl;
				cin >> k;
				try {
					vendor.displayProduct(k);
				} catch (exception error) {
					cout << "Invalid index, the amount of products is: " << vendor.getBagSize() << endl;
				}
				break;
			}
			case 6: {
				// Find the product, then prompt them for the new name and description.
				// Modify the product accordingly. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				int k;
				string description;
				cout << "Input the index of the product you want to modify:" << endl;
				cin >> k;

				// get kth product
				try {
					vendor.modifyProduct(k);
				} catch (exception error) {
					cout << "Invalid index, the amount of products is: " << vendor.getBagSize() << endl;
				}
				break;
			}
			case 7: { 
				// Find the product, then sell the product. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int k;
				int n;
				cout << "Input the index of the product you want to sell" << endl;
				cin >> k;
				cout << "Enter the quantity to sell: " << endl;
				cin >> n;

				try {
					vendor.sellProduct(k,n);
				} catch(exception error) {
					cerr << error.what() << endl;
				}
				break;
			}
			case 8:{
				// Find the product, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int k;
				cout << "input the index of the product you want to delete: " << endl;
				cin >> k;

				try {
					vendor.deleteProduct(k);
				} catch (exception error) {
					cout << "Invalid index, the amount of products is: " << vendor.getBagSize() << endl;
				}
				break;
			}
			case 0: {
				cout << "Logging you out." << endl;
				break;
			}
			default:
				cout << "Invalid choice. Please try again." << endl;
		}

	} while (vendorChoice != 0);
}

// Used for error handling 
void checkPositive(int value) {
	if (value < 0) {
		throw std::runtime_error("Error: Value must be positive!");
	}
}



int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one vendor
	Amazon340 amazon340; 

	cout << "\n Welcome to Amazon340:" << endl;
	// Instantiate a new Vendor object
	string username;
	string email;
	string password;
	string bio;
	string profilePicture;

	cout << "Please input a username: " << endl;
	cin >> username;
	cout << "Please input an email: " << endl;
	cin >> email;
	cout << "Please input a password: " << endl;
	cin >> password;
	cout << "Please input a bio: " << endl;
	cin >> bio;
	cout << "Please input a profile picture (string): " << endl;
	cin >> profilePicture;

	amazon340.createVendor(username, email, password, bio, profilePicture);

	// Retrieve the vendor 
	Vendor currentVendor = amazon340.getVendor();

	// Display the main menu
	displayVendorMenu(currentVendor);
				
	return 0;
}