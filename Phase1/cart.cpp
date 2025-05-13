#include <iostream>

using namespace std;

#include "cart.hpp"

// Add item to cart, with an amount
void ShoppingCart::addItem(Product product, int quantity) {
    int index; // Location of item in cart

    // Look for item in cart
    index = findItem(&product);

    if (index != -1) { // Already in cart, update number of items
        productCounts[index] += quantity;
    } else { // Not in cart yet, add new product and add quantity 
        products.push_back(product);
        productCounts.push_back(quantity);
    }
}

// Remove item from cart
void ShoppingCart::removeItem(Product* product) {
    // find where the item is in the vectors
    int index = findItem(product);
    
    if (index != -1) { // if it is there
        // erase the item from the vectors
        products.erase(products.begin() + index);
        productCounts.erase(productCounts.begin() + index);
    }
}

// Add item costs together
float ShoppingCart::calculateTotal() const {
    float total = 0;

    // for every item in cart, multiply price by quantity, and add to total
    for (int i = 0; i < products.size(); i++) {
        total += products[i].getPrice() * productCounts[i];
    }
    return total;
}

// Display all items' details in cart
void ShoppingCart::displayCart() const {
    if (products.size() == 0) {
        cout << "Your cart is empty.\n";
        return;
    }

    cout << "Shopping Cart Contents:\n";
    cout << "-----------------------\n";
    for (int i = 0; i < products.size(); i++) {
        // Debug
        cout << products[i].getId() << " " << products[i].getDescription() << " ";
        cout << products[i].getName() << " (x" << productCounts[i] << ")"
             << " - $" << products[i].getPrice() * productCounts[i] << endl;
    }
    cout << "-----------------------\n";
    cout << "Total: $" << calculateTotal() << "\n\n";
}

// Returns index of item in vector of products
// Take a product, return index in products, or -1 if not found
int ShoppingCart::findItem(Product* product) {
    for (int i = 0; i < products.size(); i++) {
        if (product->getName() == products[i].getName()) {
            return i;
        }
    }
    return -1;
}