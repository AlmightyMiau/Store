#include "user.hpp"

#include <fstream>

void User::saveCartToFile(ShoppingCart& cart) const {
    std::ofstream file((username + ".dat"), std::ios::binary);
    int strLen;

    const map<Product*, int>& items = cart.getItems();

    // Write how many items there are
    file << items.size() << ','; // Number of products
    // cycle through all of the pairs
    for (const auto& pair : items) {
        // Product ID
        file << pair.first << ',';
        // Quantity in cart
        file << pair.second << ',';
    }
};

void User::loadCartFromFile(ShoppingCart& cart) {
    std::ifstream file((username + ".dat"), std::ios::binary);
    int strLen;
    char *temp;

};