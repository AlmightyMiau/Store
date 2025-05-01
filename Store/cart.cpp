#include <iostream>

using namespace std;

#include "cart.hpp"

void ShoppingCart::addItem(Product* product, int quantity) {
    if (items.find(product) != items.end()) {
        items[product] += quantity;
    } else {
        items[product] = quantity;
    }
}
void ShoppingCart::removeItem(Product* product, int quantity) {
    if (items.find(product) != items.end()) {
        items[product] -= quantity;
        if (items[product] <= 0) {
            items.erase(product);
        }
    }
}
float ShoppingCart::calculateTotal() const {
    float total = 0;
    for (const auto& item : items) {
        total += item.first->getPrice() * item.second;
    }
    return total;
}
void ShoppingCart::displayCart() const {
    if (items.empty()) {
        cout << "Your cart is empty.\n";
        return;
    }

    cout << "Shopping Cart Contents:\n";
    cout << "-----------------------\n";
    for (const auto& item : items) {
        // Debug
        cout << item.first->getId() << " " << item.first->getDescription() << " ";
        cout << item.first->getName() << " (x" << item.second << ")"
             << " - $" << item.first->getPrice() * item.second << endl;
    }
    cout << "-----------------------\n";
    cout << "Total: $" << calculateTotal() << "\n\n";
}

const map<Product*, int>& ShoppingCart::getItems() const { return items; }