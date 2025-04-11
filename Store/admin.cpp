#include "admin.hpp"

using namespace std;

bool Admin::login(const string user, const string password) {
    if (!isAdmin) {
        // REMEMBER TO GET USERS FROM A FILE LATER
        vector<string> usernames = {
            "Admin"
        };
        bool found = false;
        int id = 0;

        // Find username in array
        for (int i = 0; i < usernames.size(); i++) {
            if (user == usernames[i]) {
                id = i;
                found = true;
                break;
            }
        }
        // Correct username
        if (!found) {
            cout << "Failed to login: username not found" << endl;
            return false;
        }
        // Compare password REMEMBER TO GET PASSWORDS FROM A FILE LATER
        if (password == "admin") {
            isAdmin = true;
            return true;
        } else {
            cout << "Failed to login: incorrect password" << endl;
            return false;
        }
    } else { return true; }
};

void Admin::newProduct() { // Create new product
    if (!isAdmin) {
        cout << "ERROR: User is not admin" << endl;
        return;
    }

    // id is 1 more than last id, 
    int id = store->getInventory().back().getId() + 1;
    cout << "Creating new product\n" 
        << "id: " << id << endl;

    // Get new product name
    string name;
    cout << "Name: ";
    getline(cin, name);

    // Get new product description
    string description;
    cout << "Description: ";
    getline(cin, description);

    // Get new product price
    float price;
    cout << "Price: ";
    cin >> price;

    // Get new product quantity
    int quantity;
    cout << "Quantity: ";
    cin >> quantity;

    // Ignore the whitespace!!!
    cin.ignore();

    // Create a new Product with this information, and push it into the inventory
    Product tempProduct(id, name, description, price, quantity);
    store->getInventory().push_back(tempProduct);

    // SAVE THIS TO FILE
    store->saveProductsToFile();
}

void Admin::editProduct() { // Edit a product
    if (!isAdmin) {
        cout << "ERROR: User is not admin" << endl;
        return;
    }

    // Display the products
    store->displayProductCatalog();

    // Ask for which product id to edit
    int choice;
    cout << "Select product (id) to edit: ";
    // only accept ints as input
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter a number: ";
    }
    // Ignore the whitespace!!!
    cin.ignore();
    
    // Find location of selected product
    int i = 0;
    while (i < store->getInventory().size() && choice != store->getInventory()[i].getId()) {
        i++;
    }
    if (i >= store->getInventory().size()) {
        cout << "Product not found!" << endl;
        return;
    }
    Product* currentProduct = &(store->getInventory()[i]);
    
    int selectedProperty;
    do {
        // Display Menu and ask what property to change
        cout << "======================\n"
            << " Editing Product #" << choice << "   \n"
            << "======================\n"
            << "1. Edit Name          \n"
            << "2. Edit description   \n"
            << "3. Edit price         \n"
            << "4. Edit quantity      \n"
            << "5. Exit               \n"
            << "Enter your choice: ";

        // only accept ints as input
        while (!(cin >> selectedProperty)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please enter a number: ";
        }
        cin.ignore();

        switch (selectedProperty) {
            case 1: { // Name
                string newName;
                cout << "Enter new name: ";
                getline(cin, newName);
                currentProduct->setName(newName);
                break;
            }
            case 2: { // Description
                string newDesc;
                cout << "Enter new description (one line only): ";
                getline(cin, newDesc);
                currentProduct->setDescription(newDesc);
                break;
            }
            case 3: { // Price
                float newPrice;
                cout << "Enter new price: ";
                cin >> newPrice;
                // Ignore the whitespace!!!
                cin.ignore();
                currentProduct->setPrice(newPrice);
                break;
            }
            case 4: { // Quantity
                int newQuant;
                cout << "Enter new quantity: ";
                cin >> newQuant;
                // Ignore the whitespace!!!
                cin.ignore();
                currentProduct->setQuantity(newQuant);
                break;
            }
            case 5: // Exit
                break;
        }
    } while (selectedProperty != 5);

    // SAVE THIS TO FILE
    store->saveProductsToFile();
};

void Admin::deleteProduct() { // Delete a product
    if (!isAdmin) {
        cout << "ERROR: User is not admin" << endl;
        return;
    }

    // Display the products
    store->displayProductCatalog();

    // Ask for product to delete (by id)
    int choice;
    cout << "Select product # to delete: ";
    // only accept ints as input
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please enter a number: ";
    }
    // Ignore the whitespace!!!
    cin.ignore();

    // Find location of selected product
    int i = 0;
    while (i < store->getInventory().size() && choice != store->getInventory()[i].getId()) {
        i++;
    }

    char verify;
    cout << "Are you sure you want to delete "
         << store->getInventory()[i].getName()
         << " from inventory? (y/n) ";
    cin >> verify;
    if (verify == 'y') {
        store->getInventory().erase(store->getInventory().begin() + i);
        // SAVE THIS TO FILE
        store->saveProductsToFile();
    } else {
        cout << "Canceling action" << endl;
    }
};