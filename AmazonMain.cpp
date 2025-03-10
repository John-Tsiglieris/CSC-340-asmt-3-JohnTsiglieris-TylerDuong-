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
				// TO DO: ask vendor to choose product type, then ask them to input product details.
				// Create the product and add it to the vendor's products

				// choose product type: 1: media, 2: good
					// if media: ask for type and target audience
					// if good: for expiration date and quantity
					// also need name, description. (rating and soldCount init to zero)

				// hardcoded product just for testing purposes
				string name = "Test";
				string description = "Test";
				Product* product = new Product(name, description);
				vendor.createProduct(*product);
				break;
			}
			case 4:{
				// TO DO: display all vendor's products
				//        You may re-use code from class demo
				vendor.displayAllProducts();
				break;
			}
			case 5: {
				// TO DO: ask the vendor for a value k
				// Find the Kth product, if k > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				int k;
				cout << "please enter a value k for kth product: " << endl;
				cin >> k;
				break;
			}
			case 6: {
				// TO DO: ask the vendor for the index of the product they want to modify.
				// Find the product, then prompt them for the new name and description.
				// Modify the product accordingly. 
				// If index > Linked Bag size, 
				//    return an error message that includes the size of the Linked Bag
				int k;
				string description;
				cout << "Input the index of the product you want to modify" << endl;
				cin >> k;
				cout << "input the description of the product you want to modify" << endl;
				cin >> description;
				// How to modify product if it only takes k as a param and returns bool?
				break;
			}
			case 7: {
				// TO DO: ask the vendor for the index of the product they want to sell 
				// Find the product, then sell the product. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int k;
				int n;
				cout << "Input the index of the product you want to sell: " << endl;
				cin >> k;
				cout << "Enter the quantity to sell: " << endl;
				cin >> n;
				vendor.sellProduct(k,n);
				break;
			}
			case 8:{
				// TO DO: ask the vendor for the index of the product they want to delete 
				// Find the product, then remove it from the list. 
				// If index > LinkedBag size, 
				//    return an error message that includes the size of the Linked Bag
				int k;
				cout << "input the index of the product you want to delete: " << endl;
				cin >> k;
				vendor.deleteProduct(k);
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



int main(){
	// Instantiating the program using the default constructor
	// With this implementation, the application will only have one vendor
	Amazon340 amazon340; 

	cout << "\n Welcome to Amazon340:" << endl;
	// TO DO: Ask the vendor to enter their information 
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