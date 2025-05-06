#include "user.hpp"

#include <fstream>
#include <iostream> // Debug

void User::saveCartToFile(ShoppingCart& cart) const {
    std::ofstream file((username + ".dat"), std::ios::binary);
    int strLen;

    vector<Product> products = *cart.getItems();
    vector<int> quantities = *cart.getItemQuantities();

    // Write how many items there are
    // Size
    int size = products.size();// Number of products
    file.write(reinterpret_cast<const char*>(&size),sizeof(size));
    
    // cycle through all of the pairs
    for (int i = 0; i < products.size(); i++) {
        // ID, name, description, price, quant of product, quant in cart
        // ID
        int id = products[i].getId();
        file.write(reinterpret_cast<const char*>(&id),sizeof(id));

        // Name
        strLen = products[i].getName().size();
        file.write(reinterpret_cast<const char*>(&strLen), sizeof(strLen));
        file.write(products[i].getName().c_str(),strLen);
        
        // Description
        strLen = products[i].getDescription().size();
        file.write(reinterpret_cast<const char*>(&strLen), sizeof(strLen));
        file.write(products[i].getDescription().c_str(),strLen);
        
        // Price
        float price = products[i].getPrice();
        file.write(reinterpret_cast<const char*>(&price),sizeof(price));
        
        // Quant
        int quant = products[i].getQuantity();
        file.write(reinterpret_cast<const char*>(&quant),sizeof(quant));

        // Quantity
        int quantity = quantities[i];
        file.write(reinterpret_cast<const char*>(&quantity),sizeof(quantity));
    }
};

void User::loadCartFromFile(ShoppingCart& cart) {
    std::ifstream file((username + ".dat"), std::ios::binary);
    int strLen;
    char *temp;

    if (file.peek() == ifstream::traits_type::eof()) { // File is empty
        return;
    }

    // Read number of items
    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    if (size == 0) return;

    for (int i = 0; i < size; i++) {
        // Product ID
        int id;
        file.read(reinterpret_cast<char*>(&id), sizeof(id));

        // Product Name
        string name;
        file.read(reinterpret_cast<char*>(&strLen),sizeof(strLen));
        temp = new char[strLen +1];
        file.read(temp,strLen);
        temp[strLen] = '\0';
        name = temp;
        delete [] temp;

        // Product Description
        string desc;
        file.read(reinterpret_cast<char*>(&strLen),sizeof(strLen));
        temp = new char[strLen +1];
        file.read(temp,strLen);
        temp[strLen] = '\0';
        desc = temp;
        delete [] temp;

        // Product Price
        float price;
        file.read(reinterpret_cast<char*>(&price), sizeof(price));

        // Product Quantity
        int quant;
        file.read(reinterpret_cast<char*>(&quant), sizeof(quant));

        Product product(id,name,desc,price,quant);

        // Quantity in cart
        int quantity;
        file.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));

        cart.addItem(product, quantity);
    }
    file.close();
};

void User::logout() {
    admin = false;
    logged = false;
    username = " ";
    password = " ";
}