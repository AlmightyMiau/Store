#include "user.hpp"

#include <fstream>
#include <iostream> // Debug

void User::saveCartToFile(ShoppingCart& cart) const {
    std::ofstream file((username + ".dat"), std::ios::binary);
    int strLen;

    const map<Product*, int>& items = cart.getItems();

    // Write how many items there are
    // Size
    int size = items.size();// Number of products
    file.write(reinterpret_cast<const char*>(&size),sizeof(size));
    cout << "size " << size << endl;
    
    // cycle through all of the pairs
    for (const auto& pair : items) {
        // ID, name, description, price, quant of product, quant in cart
        // ID
        int id = pair.first->getId();
        file.write(reinterpret_cast<const char*>(&id),sizeof(id));
        cout << "ID " << id << endl;

        // Name
        strLen = pair.first->getName().size();
        file.write(reinterpret_cast<const char*>(&strLen), sizeof(strLen));
        file.write(pair.first->getName().c_str(),strLen);
        cout << "strlen " << strLen << endl;
        cout << "Name " << pair.first->getName() << endl;
        
        // Description
        strLen = pair.first->getDescription().size();
        file.write(reinterpret_cast<const char*>(&strLen), sizeof(strLen));
        file.write(pair.first->getDescription().c_str(),strLen);
        cout << "strlen " << strLen << endl;
        cout << "Desc " << pair.first->getDescription() << endl;
        
        // Price
        float price = pair.first->getPrice();
        file.write(reinterpret_cast<const char*>(&price),sizeof(price));
        cout << "Price " << price << endl;
        
        // Quant
        int quant = pair.first->getQuantity();
        file.write(reinterpret_cast<const char*>(&quant),sizeof(quant));
        cout << "Quant " << quant << endl;

        // Quantity
        int quantity = pair.second;
        file.write(reinterpret_cast<const char*>(&quantity),sizeof(quantity));
        cout << "Quantity " << quantity << endl;
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
    cout << "size " << size << endl;

    if (size == 0) return;

    for (int i = 0; i < size; i++) {
        // Product ID
        int id;
        file.read(reinterpret_cast<char*>(&id), sizeof(id));
        cout << "ID " << id << endl;

        // Product Name
        string name;
        file.read(reinterpret_cast<char*>(&strLen),sizeof(strLen));
        temp = new char[strLen +1];
        file.read(temp,strLen);
        temp[strLen] = '\0';
        name = temp;
        delete [] temp;
        cout << "strlen " << strLen << endl;
        cout << "Name " << name << endl;

        // Product Description
        string desc;
        file.read(reinterpret_cast<char*>(&strLen),sizeof(strLen));
        temp = new char[strLen +1];
        file.read(temp,strLen);
        temp[strLen] = '\0';
        desc = temp;
        delete [] temp;
        cout << "strlen " << strLen << endl;
        cout << "Desc " << desc << endl;

        // Product Price
        float price;
        file.read(reinterpret_cast<char*>(&price), sizeof(price));
        cout << "Price " << price << endl;

        // Product Quantity
        int quant;
        file.read(reinterpret_cast<char*>(&quant), sizeof(quant));
        cout << "Quant " << quant << endl;

        Product product(id,name,desc,price,quant);

        // Quantity in cart
        int quantity;
        file.read(reinterpret_cast<char*>(&quantity), sizeof(quantity));
        cout << "Quantity " << quantity << endl;

        cart.addItem(&product, quantity);

        cout << "ID " << product.getId() << endl;
        cout << "name " << product.getName() << endl;
        cout << "desc " << product.getDescription() << endl;
        cout << "price " << product.getPrice() << endl;
        cout << "quantity " << product.getQuantity() << endl;
    }
    file.close();
};

void User::logout() {
    admin = false;
    logged = false;
    username = " ";
    password = " ";
}