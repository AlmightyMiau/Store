#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <limits>
#include <iomanip>

using namespace std;

#include "product.hpp"
#include "cart.hpp"
#include "storeFront.hpp"
#include "admin.hpp"


int main() {
    StoreFront store;
    store.loadProductsFromFile();
    Admin admin(&store);

    while (true) {
        cout << "======================\n"
             << "   Store Front Menu   \n"
             << "======================\n"
             << "1. View Products      \n"
             << "2. View Cart          \n"
             << "3. Checkout           \n"
             << "4. Login              \n"
             << "5. Exit               \n"
             << "Enter your choice: ";

        int choice;
        // only accept ints as input
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a number: ";
        }

        switch (choice) {
            case 1: { // View Products
                store.displayProductCatalog();
                cout << "Enter product ID to add to cart (or 0 to return): ";
                int productId;
                cin >> productId;
                
                if (productId == 0) break;
                
                Product* product = store.getProductById(productId);
                if (product) {
                    cout << "Enter quantity: ";
                    int quantity;
                    while (!(cin >> quantity) || quantity <= 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid quantity. Please enter a positive number: ";
                    }
                    
                    if (quantity > product->getQuantity()) {
                        cout << "Error: Not enough stock available.\n";
                    } else {
                        store.getCart().addItem(product, quantity);
                        cout << "Added " << quantity << " of " << product->getName() << " to cart.\n";
                    }
                } else {
                    cout << "Invalid product ID.\n";
                }
                break;
            }
            
            case 2: // View Cart
                store.getCart().displayCart();
                break;
            
            case 3: // Checkout
                store.processOrder();
                break;

            case 4: { // Login
                    string password;
                if (!admin.islogged()) {
                    cout << "Input Admin password: ";
                    cin >> password;
                }
                if (admin.login("Admin", password) || admin.islogged()) {
                    int adminChoice;
                    do {
                        // Display Admin Menu
                        cout << "======================\n"
                            << "      Admin Menu      \n"
                            << "======================\n"
                            << "1. View Products      \n"
                            << "2. Edit Product       \n"
                            << "3. Create Product     \n"
                            << "4. Delete Product     \n"
                            << "5. Exit               \n"
                            << "Enter your choice: ";

                        // only accept ints as input
                        while (!(cin >> adminChoice)) {
                            cin.clear();
                            cin.ignore();
                            cout << "Invalid input. Please enter a number: ";
                        }

                        switch (adminChoice) {
                            case 1: 
                                store.displayProductCatalog();
                                break;
                            case 2:
                                admin.editProduct();
                                break;
                            case 3:
                                admin.newProduct();
                                break;
                            case 4:
                                admin.deleteProduct();
                                break;
                            default:
                                break;
                        }
                    } while (adminChoice != 5);
                }
                break;
            }
            
            case 5:
                store.saveProductsToFile();
                cout << "Thank you for shopping with us!\n";
                return 0;
            
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}