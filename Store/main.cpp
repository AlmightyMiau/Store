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

int main() {
    StoreFront store;
    store.loadProductsFromFile("products.txt");

    while (true) {
        cout << "======================\n"
             << "   Store Front Menu   \n"
             << "======================\n"
             << "1. View Products\n"
             << "2. View Cart\n"
             << "3. Checkout\n"
             << "4. Exit\n"
             << "Enter your choice: ";

        int choice;
        // only accept ints as input
        while (!(cin >> choice)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a number: ";
        }

        switch (choice) {
            case 1: {
                store.displayProductCatalog();
                cout << "Enter product ID to add to cart (or 0 to return): ";
                string productId;
                cin >> productId;
                
                if (productId == "0") break;
                
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
            
            case 2:
                store.getCart().displayCart();
                break;
            
            case 3:
                store.processOrder();
                break;
            
            case 4:
                store.saveProductsToFile("products.txt");
                cout << "Thank you for shopping with us!\n";
                return 0;
            
            default:
                cout << "Invalid choice. Please try again.\n";
        }
        
        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}