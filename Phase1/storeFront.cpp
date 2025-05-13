#include "storeFront.hpp"

void StoreFront::updateInventory() {
    vector<Product>* products = currentCart.getItems();
    vector<int>* quantities = currentCart.getItemQuantities();
    for (int i = 0; i < products->size(); i++) {
        // set the quantity, of the product given by products[i], to the current quantity there, minus the quantity given 
        // the [0]'s are used to select the item instead of the allocator (??? very silly)
        Product* product = getProductById(products[i][0].getId());
        product->setQuantity(products[i][0].getQuantity() - quantities[i][0]);
    }
}

void StoreFront::loadProductsFromFile() {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    inventory.clear();
    while (getline(file, line)) {
        stringstream ss(line);
        string id, name, desc, priceStr, qtyStr;
        
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, desc, ',');
        getline(ss, priceStr, ',');
        getline(ss, qtyStr, ',');

        try {
            float price = stof(priceStr);
            int quantity = stoi(qtyStr);
            inventory.emplace_back(id, name, desc, price, quantity);
        } catch (...) {
            cerr << "Error parsing line: " << line << endl;
        }
    }
    file.close();
}

void StoreFront::saveProductsToFile() {
    ofstream file(filename);
    for (const auto& product : inventory) {
        file << product.getId() << ","
             << product.getName() << ","
             << product.getDescription() << ","
             << product.getPrice() << ","
             << product.getQuantity() << "\n";
    }
    file.close();
}

void StoreFront::displayProductCatalog() {
    // loadProductsFromFile();
    cout << "\nProduct Catalog:\n";
    cout << "----------------\n";
    for (const Product& product : inventory) {
        product.display();
    }
}

Product* StoreFront::getProductById(const int& id) {
    for (auto& product : inventory) {
        if (product.getId() == id) {
            return &product;
        }
    }
    return nullptr;
}

void StoreFront::processOrder() {
    currentCart.displayCart();
    float total = currentCart.calculateTotal();
    
    if (total > 0) {
        cout << "Proceeding to checkout...\n";
        cout << "Total amount: $" << fixed << setprecision(2) << total << endl;
        
        int confirmChoice;
        cout << "Confirm purchase:\n"
            << "1. Confirm\n"
            << "2. Cancel\n"
            << "Choice: ";
        while (!(cin >> confirmChoice) || (confirmChoice < 1 || confirmChoice > 2)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid choice. Please enter 1 or 2: ";
        }
        if (confirmChoice == 2) return; // Cancel order
        
        
        updateInventory();
        saveProductsToFile();
        currentCart.clearCart();
        cout << "Payment processed successfully!\n\n";
    }
}