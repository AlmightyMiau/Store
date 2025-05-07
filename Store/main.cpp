#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

#include "product.hpp"
#include "cart.hpp"
#include "storeFront.hpp"
#include "admin.hpp"
#include "userManagement.hpp"
#include "user.hpp"


int main() {
    StoreFront store;
    store.loadProductsFromFile();
    Admin admin(&store); 
    UserManagement Users; // Methods to manage users
    User currentUser; // User info once logged in
    Users.loadFromFile();


    while (true) {
        cout << "======================\n"
             << "   Store Front Menu   \n"
             << "======================\n";
        if (currentUser.isLogged()) {
            cout << "Logged in as " << currentUser.getUsername() << endl;
        }
        cout << "0. Exit               \n"
             << "1. View Products      \n"
             << "2. View Cart          \n"
             << "3. Checkout           \n";
        if (!currentUser.isLogged()) {
            cout << "4. Login              \n"
                << "5. Signup             \n";
        } else {
            cout << "4. Logout             \n";
            if (currentUser.isAdmin()) {
                cout << "5. Access Admin Panel \n";
            }
        }
        cout << "Enter your choice: ";

        int choice;
        // only accept ints as input
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a number: ";
        }

        switch (choice) {
            case 0: // Exit
                store.saveProductsToFile();
                if (currentUser.isLogged()) currentUser.saveCartToFile(store.getCart());
                cout << "Thank you for shopping with us!\n";
                return 0;
            
            case 1: { // View Products
                store.displayProductCatalog();
                cout << "Enter product ID to add to cart (or 0 to return): ";
                int productId;
                cin >> productId;
                
                if (productId == 0) break;
                
                Product* product = store.getProductById(productId);
                if (product) {
                    cout << "Enter quantity (or 0 to cancel): ";
                    int quantity;
                    while (!(cin >> quantity) || quantity < 0) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Invalid quantity. Please enter a positive number: ";
                    }
                    if (quantity == 0) break;
                    
                    if (quantity > product->getQuantity()) {
                        cout << "Error: Not enough stock available.\n";
                    } else {
                        store.getCart().addItem(*product, quantity);
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
                if (currentUser.isLogged()) { currentUser.saveCartToFile(store.getCart()); }
                break;

            case 4: { // Login or Logout
                if (!currentUser.isLogged()) { // Login
                    Users.login(currentUser);
                    currentUser.loadCartFromFile(store.getCart());
                } else { // Logout
                    currentUser.saveCartToFile(store.getCart());
                    store.getCart().clearCart();
                    currentUser.logout();
                }
                break;
            }
            
            case 5: // Signup or Access admin panel
                if (!currentUser.isLogged()) {
                    Users.addUser(currentUser);
                    currentUser.setLogged(true);
                    currentUser.loadCartFromFile(store.getCart());
                } else if (currentUser.isAdmin()) {
                    // If user is admin, give them admin menu
                    // If not, user can use normal program
                    int adminChoice;
                    do {
                        // Display Admin Menu
                        cout << "======================\n"
                            << "      Admin Menu      \n"
                            << "======================\n"
                            << "0. Exit               \n"
                            << "1. View Products      \n"
                            << "2. Edit Product       \n"
                            << "3. Create Product     \n"
                            << "4. Delete Product     \n"
                            << "5. User data          \n"
                            << "6. Delete User        \n"
                            << "Enter your choice: ";

                        // only accept ints as input
                        while (!(cin >> adminChoice)) {
                            cin.clear();
                            cin.ignore();
                            cout << "Invalid input. Please enter a number: ";
                        }

                        // variables used in here
                        int index; // index of user to delete
                        switch (adminChoice) {
                            case 0: // Exit
                                break;
                            case 1: 
                                cin.ignore(); // Remove whitespace so Admin::NewProduct() will work
                                store.displayProductCatalog();
                                break;
                            case 2:
                                cin.ignore(); // Remove whitespace so Admin::NewProduct() will work
                                admin.editProduct();
                                break;
                            case 3:
                                cin.ignore(); // Remove whitespace so Admin::NewProduct() will work
                                admin.newProduct();
                                break;
                            case 4:
                                cin.ignore(); // Remove whitespace so Admin::NewProduct() will work
                                admin.deleteProduct();
                                break;
                            case 5:
                                Users.printUsers(currentUser);
                                break;
                            case 6: // Delete a user
                                Users.printUsers(currentUser);
                                cout << "Select index of user to delete: ";
                                cin >> index;
                                Users.deleteUser(index);
                                break;
                        }
                    } while (adminChoice != 0);
                }
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}