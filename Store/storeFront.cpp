#include "storeFront.hpp"

void StoreFront::updateInventory() {
    for (const auto& item : currentCart.getItems()) {
        Product* product = item.first;
        int quantity = item.second;
        product->setQuantity(product->getQuantity() - quantity);
    }
}

void StoreFront::loadProductsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    string line;
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

void StoreFront::saveProductsToFile(const string& filename) {
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

void StoreFront::displayProductCatalog() const {
    cout << "\nProduct Catalog:\n";
    cout << "----------------\n";
    for (const auto& product : inventory) {
        product.display();
    }
}

Product* StoreFront::getProductById(const string& id) {
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
        processPayment(total);
        updateInventory();
        saveProductsToFile("products.txt");
        currentCart.clearCart();
    }
}

void StoreFront::processPayment(float amount) {
    cout << "Total amount: $" << fixed << setprecision(2) << amount << endl;
    
    int paymentChoice;
    cout << "Select payment method:\n"
         << "1. Credit Card\n"
         << "2. Debit Card\n"
         << "Choice: ";
    
    while (!(cin >> paymentChoice) || (paymentChoice < 1 || paymentChoice > 2)) {
        cin.clear();
        cin.ignore();
        cout << "Invalid choice. Please enter 1 or 2: ";
    }
    
    cout << "Payment processed successfully!\n\n";
}